import keras.layers as lys
import keras
from keras.utils.vis_utils import plot_model
import utils
import constants

utils.generate_sa_data()

_, _, mapping, _, _ = utils.load_data(constants.WORKING_DIR_SA_DATA)
print(mapping)

# shape = (1, 2, 3)
# print(shape[-2:])

# import pydot
#
# model = keras.Sequential()
# model.add(lys.Embedding(16, 8))
# model.add(lys.Dense(128))
#
# ip1 = keras.Input(shape=(10, 10))
# ip2 = keras.Input(shape=(16, 16))
#
# model(ip1)
# model(ip2)
#
# plot_model(model)
