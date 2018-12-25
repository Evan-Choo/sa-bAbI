# Author: Yiner

"""test_trueC.py: test memory network models on true C files"""

import os

import keras.models
import matplotlib.pyplot as plt
import numpy as np
import sklearn.metrics

# if user-specific constants exist, import them and override
try:
    import user_constants as constants
except ImportError:
    import constants
import datagen
import utils
import validate
from sa_babi.sa_tag import Tag


def get_tok_fnames(working_dir):
    """Get the list of the paths of *.c.tok files

    Args:
        working_dir: dir path where *.c.tok files are located
    Returns:
    	path_list: the list of the paths of *.c.tok files
    """
    fname_suffix = ".c.tok"
    tok_dir = os.path.join(working_dir,'tokens')
    contents = sorted(os.listdir(tok_dir))
    if not contents:
        raise IOError("Empty test token dir: '%s'" % tok_dir)
    path_list = [os.path.join(tok_dir, fname)
                 for fname in contents
                 if fname.endswith(fname_suffix)]
    return path_list

def get_memnet_predics(working_dir, models_dir, fnames=None, line_num=None):
    """Get memory network predictions

    Args:
        working_dir (str): path to working dir with data in .npy files
        models_dir (str): path to models dir with models in .h5 files
        fnames (str or list of str): filenames to get predictions from
            if None, then get them for all validation files
        line_num (int): line number to predict
            if None, then get predictions for all lines
    Returns: (only test one line query)
        y_true_list: the list of true labels of the query lines
        predict_list:  the list of the predict labels of the query lines
        line_num_list:  the list of the query line numbers
    """
    # load data
    inst, lab, _, part, paths = utils.load_data(working_dir)

    # get trained model
    models = validate.get_models(models_dir)

    if fnames is None:
        fnames = [paths[idx] for idx in part['validation']]
    elif isinstance(fnames, str):
        fnames = [fnames]
    elif not isinstance(fnames, list):
        raise ValueError("fnames must be str, list, or None")

    if line_num is not None:
        # -1 for line numbers starting at 1
        # -1 for excluding the #include
        line_num = line_num - 2

    val_data_generator = datagen.DataGenerator(working_dir=working_dir)

    y_true_list = []
    predict_list = []
    line_num_list = []

    for fname in fnames:
        print("fname: {}".format(fname))

        # get file number
        file_num = None
        for idx, path in enumerate(paths):
            if fname in path:
                file_num = idx
        if file_num is None:
            raise ValueError("Could not find file {}".format(fname))

        if line_num is not None:
            line_nums = np.array([line_num])
        else:
            line_nums = np.where(lab[file_num])[0]
        num_queries = line_nums.shape[0]
        line_num_list.append(line_nums)
        print("Querying {} lines".format(num_queries))

        # get data matrices
        (instances_mat, queries_mat), labels_mat = (val_data_generator.get_test_c_samples([file_num]))

        y_true = np.argmax(labels_mat, axis=1)
        y_true_list.append(y_true)

        # get predictions
        separate_predics = []
        for predic_num in range(validate.NUM_MODELS_PER_EXPERIMENT):
            predic = models[predic_num].predict([instances_mat, queries_mat])

            separate_predics.append(predic)

        # convert to labels
        separate_predics = [np.argmax(y_pred, axis=1) for y_pred in separate_predics]
        predict_list.append(separate_predics)

    return y_true_list, predict_list, line_num_list


if __name__ == '__main__':
    test_dir = 'sa-test-trueC'
    working_dir = os.path.join(constants.VALIDATION_WORKING_PARENT_DIR, test_dir)
    tok_dir = os.path.join(working_dir, 'tokens')

    # generate sa_data from true c code
    utils.generate_true_c_sa_data(working_dir=working_dir, tok_dir=tok_dir)

    models_dir = os.path.join(constants.VALIDATION_MODELS_PARENT_DIR,
                              constants.VALIDATION_MODELS_SUBDIRS[-1])
    tok_fnames = get_tok_fnames(working_dir)

    # predict
    labels, predics, line_list = get_memnet_predics(working_dir, models_dir, fnames=tok_fnames)
    result_tuple_list = []

    # labels
    true_labels = []
    for label_list in labels:
        for label in label_list:
            true_labels.append(Tag(label + 2))

    # predicts
    predict_list = [[] for i in range(len(predics))]
    predict_result = []
    for index, inst in enumerate(predics):
        for predicts in inst:
            for predict in predicts:
                predict_list[index].append(predict)
        predict_count = np.bincount(predict_list[index])
        predict_result.append(Tag(np.argmax(predict_count)+2))

    # print result
    print("Results are: ")
    for index, file in enumerate(tok_fnames):
        print("file {0}, querying line {1}, true label is {2}, predict label is {3}.".format(
            os.path.basename(file), line_list[index], true_labels[index], predict_result[index]))
