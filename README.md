# laboratorioscc7
Laboratorios clase cc7
Laboratorio
Descripción de Creación de Procesos:

                    En Linux
Los procesos creados con la función fork(), después de crear
un nuevo Child process , ambos procesos (Child and Parent)
ejecutarán la siguiente instrucción después del Syscall. Un
proceso secundario usa el mismo PC (Program Counter), los
mismos registros de CPU, los mismos archivos abiertos que se
usan en el proceso primario.
En el archivo linux.c se utiliza fork(), el cual al ser
llamado crea un subproceso que ejecuta ls ( l i s t files and
documents).


                    En Windows
Ahora analicemos la creación de procesos en Windows. Los
procesos son creados utilizando el API Win32, con la función
CreateProcess() , y se diferencia del fork() en el hecho que en
vez de heredar el address space de su parent, CreateProcess()
requiere especificar el nombre del programa a cargar en el
address space del nuevo proceso. Además fork() no requiere
parámetros, mientras que CreateProcess() espera no menos de 10
parámetros.
En el archivo windows.c se utiliza CreateProcess() , el cual
crea un nuevo proceso que carga en memoria mspaint.exe . De
momento utilizaremos los valores default para la mayoría de
parámetros del CreateProcess(). Para probar este código podría
crear un proyecto en DevC , o en cualquier compilador de C
para Windows. (Nota, este programa es del tipo Console
Application.)
Dos de los parámetros enviados a CreateProcess() son
instancias de las estructuras STARTUPINFO y
PROCESS_INFORMATION . STARTUPINFO específica muchas de las
propiedades para el nuevo proceso, como por ejemplo el tamaño
y apariencia de la ventana, así como los handlers para el
input y output. La estructura PROCESS_INFORMATION contiene el
handler e identificadores asociados al proceso que se está
creando y a su hilo de ejecución. La función ZeroMemory()
sirve para reservar la memoria para cada una de estas
estructuras antes de invocar al método CreateProcess() .
Los dos primeros parámetros que se envían al CreateProcess()
son el nombre de la aplicación y los parámetros de línea de
comando. Si el nombre de la aplicación se envía como NULL , el
segundo parámetro especifica la aplicación a cargar. En este
caso se está levantando una instancia del mspaint.exe .



                     Actividades:
Coloque sus respuestas en un archivo .txt ( respuestas.txt )
Procesos en Windows:
1. ¿Cuál es el resultado de este programa?
2. Ejecute el programa procexp.exe que se encuentra en la
carpeta Soporte a los Laboratorios del GES. Tome su
tiempo para revisar y explorar las funcionalidades de la
aplicación.
3. Con el procexp.exe corriendo, vuelva a ejecutar el código
anterior. Analice y revise la estructura del árbol de
procesos. ¿Qué relación tiene su programa con el
mspaint.exe ?
4. ¿Qué sucede en el árbol de procesos si cierra la ventana
de consola asociada a su programa? ¿ mspaint.exe continua
activo?
5. Para analizar el funcionamiento de la instrucción
WaitForSingleObject() , pruebe comentar la llamada a dicha
función y observe el comportamiento de su programa en el
árbol de procesos.
6. ¿Existe alguna similitud entre las instrucciones wait() y
WaitForSingleObject() de los programas que ejecuta en
Linux y Windows?
Procesos en Linux:
1. ¿Cuál es el resultado de este programa?
2. Describa paso a paso lo que sucede en este programa.
3. ¿Qué sucede si comenta la instrucción wait(NULL) ?,
¿Cambian los resultados? ¿Por qué?
4. ¿Cuál es la función de los if que validan la variable pid
(process id)?
5. ¿Qué sección de código o programa se ejecuta cuando se
crea el nuevo proceso? (Indique lo que sucede al momento
de ejecutar las instrucciones fork() y execlp() )
Entrega:
● El laboratorio debe ser entregado por medio del GES, con
todos los archivos en un ZIP . No se calificarán
laboratorios entregados tarde o por medio de URL externo.
● El laboratorio puede tener una calificación de -100 si se
detecta.
Para este Laboratorio se adjunta un archivo ZIP con el código
a compilar en ambos sistemas, además de procexp.exe para
windows, puede hacer uso de ello para realizar su laboratorio.
