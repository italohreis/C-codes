import pandas as pd
import tensorflow as tf
import matplotlib.pyplot as plt
from keras.models import Sequential
from keras.layers import Dense
import openpyxl
from openpyxl import *

#
data = pd.read_excel('i.xlsx')
data = data.iloc[:,1:5]
data_n = (data-data.min()) / (data.max()-data.min())

#
data_t = data_n.sample(frac=0.7, random_state=0)
data_v = data_n.drop(data_t.index)

#
x_t = data_t.iloc[:, 0:3]
y_t = data_t.iloc[:, 3]
x_v = data_v.iloc[:, 0:3]
y_v = data_v.iloc[:, 3]

#
model = Sequential()
#
model.add(Dense(7, input_dim=3, activation="sigmoid"))
#
model.add(Dense(1, activation="sigmoid"))

#
opt = tf.keras.optimizers.SGD(learning_rate=0.2,momentum=0.8)
#
model.compile(loss="mse", optimizer=opt, metrics=["mae"])

#
mf = model.fit(x_t,y_t, epochs=50, batch_size=1, validation_data=(x_v,y_v))

#
saidas_estimadas = model.predict(x_v)

#
#
weights1, biases1 = model.layers[0].get_weights()
#
weights2, biases2 = model.layers[1].get_weights()

#gráficos
plt.figure(figsize=[6,4])
plt.plot(mf.history['loss'], 'blue', linewidht=2.0)
plt.plot(mf.history['val_loss'], 'red', linewidht=2.0)
plt.legend(['Treinamento', 'Validação'], fontsize=14)
plt.xlabel('Épocas', fontsize=10)
plt.ylabel('EQM', fontsize=10)
plt.title('Gráfico EQM', fontsize=12)

plt.figure(figsize=[6,4])
plt.plot(mf.history['mae'], 'blue', linewidth=2.0)
plt.plot(mf.history['val_mae'], 'red', linewidth=2.0)
plt.legend(['treinamento', 'validação'], fontsize=14)
plt.xlabel('epocas', fontsize=10)
plt.ylabel('ERM', fontsize=10)
plt.title('Gráfico ERM', fontsize=12)

plt.figure(figsize=[6,4])
plt.plot(list(range(len(saidas_estimadas))),saidas_estimadas, 'blue' , linewidht=2.0)
plt.plot (list(range(len(saidas_estimadas))),y_v, 'red', linewidht=2.0)
plt.legend(['Estimado' , 'Esperado'], fontsize=14)
plt.xlabel('Amostras', fontsize=10)
plt.ylabel('pu', fontsize=10)
plt.title('Saídas estimadas x Saídas esperadas', fontsize=12)

plt.show()
