import matplotlib.pyplot as plt

archivo = 'bandwitdhtxt'


tamanho = []
bw1pc = []
bw2pc = []

with open(archivo, 'r') as file:
    for linea in file:
        datos = linea.strip().split(',')
        tamanho.append(float(datos[0]))
        bw1pc.append(float(datos[1]))
        bw2pc.append(float(datos[2]))

plt.style.use('ggplot')
plt.figure(figsize=(10, 6))
plt.plot(tamaño, bw1pc, label='BW1pc', marker='o')
plt.plot(tamaño, bw2pc, label='BW2pc', marker='o')


plt.title('Gráfica de BW1pc y BW2pc vs Tamaño')
plt.xlabel('Tamaño')
plt.ylabel('Bandwitdh')
plt.legend()
plt.grid(True)

plt.savefig('banwitdh.pdf')
