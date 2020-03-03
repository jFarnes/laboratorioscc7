# laboratorioscc7
Laboratorios clase cc7

Laboratorio
Disk Scheduling
Ciencias de la Computación VII
El objetivo de este laboratorio es que el alumno conozca los
Disk scheduling que los sistemas operativos implementan para
acceder a disco.
Instrucciones:
En el presente laboratorio debe implementar un sistema
que permita evaluar el rendimiento de los siguientes
algoritmos:
FIFO
Scan
C-Scan
SSTF
Permitir al usuario el ingreso de N requerimientos a disco
duro (No se hará diferencia entre operaciones de Lectura y
Escritura). Dichos requerimientos deben ser almacenados en una
cola. Además, debe solicitar la posición inicial de la cabeza
lectora y la dirección en la que se está moviendo.
Para este laboratorio, la cabeza lectora se puede mover hacia
la izquierda o hacia la derecha (Esto para facilitar la
calendarización de la cola de requerimientos). Al finalizar el
ingreso de datos, su programa debe mostrar en pantalla el
contenido de la cola a calendarizar y proceder a simular la
ejecución de cada uno de los algoritmos listados
anteriormente.
Formato:
Por cada simulación debe mostrar en pantalla la siguiente
información:
[Nombre del algoritmo]
[Posición inicial de la cabeza lectora]
[Listado de accesos a disco duro, según su simulación]
[Promedio de desplazamientos que la cabeza lectora ha realizado por lectura]
[Desviación Estándar de los desplazamientos que la cabeza lectora ha realizado por lectura]
Ejemplo:
Si la cola tiene los siguientes elementos: 34, 45, 67, 89
y la cabeza lectora está en la posición 50, para el SSTF
debería mostrar:
Shortest Seek Time First
Posición Inicial: 50
Listado: 45,34,67,89
Promedio: 17.75
Desviación Estándar: 12.36
Donde el promedio se calculó del SSTF de la siguiente forma:
Promedio = (5 + 11 + 33 + 22)/4 = 17.75
De la misma forma debe mostrar la información para el resto de
algoritmos.
Asuma un disco duro que posee 100 bloques.
Preguntas (respuestas.txt)
1. En base a sus pruebas, ¿Qué algoritmo tuvo mejores
resultados? Justifique.
2. ¿Cómo funciona un SSD (Disco de Estado Sólido)?
3. ¿Cuál es el comportamiento de estos algoritmos en un SSD?
4. ¿Existen Disk Scheduling para un SSD? Justifique.
Entrega:
● El laboratorio debe ser realizado en C.
● El laboratorio debe ser entregado por medio del GES, con
todos los archivos en un ZIP. No se calificarán
laboratorios entregados tarde o por medio de URL externo.
● El laboratorio debe de contener un archivo Makefile ya
sea que requiera o no cargar librerías para realizar la
compilación.
● El laboratorio puede tener una calificación de cero si no
compila o de -100 si se detecta plagio.
Referencia con implementaciones
https://www.geeksforgeeks.org/disk-scheduling-algorithms/
