REPOSITORIO 

Bienvenido a este repositorio, creado como parte de mi formación en **Ingeniería de Sistemas** en la **Pontificia Universidad Javeriana**. Este proyecto forma parte de la asignatura de **Sistemas Operativos**, una de las materias fundamentales en el plan de estudios, ya que nos sumerge en el funcionamiento interno de las computadoras y nos permite entender cómo los sistemas gestionan los recursos de hardware y software de manera eficiente.  

#### ¿Qué es un Sistema Operativo?  
Un **Sistema Operativo (SO)** es el software principal que actúa como intermediario entre los usuarios y el hardware del computador. Su propósito principal es gestionar los recursos del sistema, como el procesador, la memoria, los dispositivos de almacenamiento y los periféricos, de forma que diferentes aplicaciones puedan ejecutarse de manera eficiente y segura.  

Entre las principales funciones de un sistema operativo se encuentran:  
1. **Gestión de Procesos**: Coordina la ejecución de programas, gestionando el uso del procesador y proporcionando multitarea.  
2. **Gestión de Memoria**: Asigna y libera espacio en la memoria principal (RAM) para que los programas puedan ejecutarse correctamente.  
3. **Gestión de Almacenamiento**: Organiza y controla el acceso a los dispositivos de almacenamiento, como discos duros o SSDs.  
4. **Control de Dispositivos**: Interactúa con el hardware mediante controladores que permiten la comunicación entre el software y los dispositivos físicos.  
5. **Interfaz de Usuario**: Ofrece un entorno para que los usuarios puedan interactuar con el sistema, ya sea mediante una interfaz gráfica (GUI) o línea de comandos (CLI).  

Los sistemas operativos son esenciales para el funcionamiento de cualquier dispositivo computacional, desde computadoras personales y servidores hasta smartphones, consolas de videojuegos e incluso sistemas embebidos.  

#### ¿Qué es la Jerarquía de Memoria y Cómo Funciona?  
La **jerarquía de memoria** es un modelo conceptual que organiza los diferentes tipos de memoria en un sistema computacional en niveles, basándose en su velocidad, capacidad y costo. Este modelo es fundamental para los sistemas operativos, ya que permite gestionar eficientemente los datos y las instrucciones que los programas necesitan en tiempo de ejecución.  

La jerarquía se compone de los siguientes niveles, ordenados de mayor velocidad y menor capacidad (en la parte superior) a menor velocidad y mayor capacidad (en la parte inferior):  

1. **Registros**:  
   Son las memorias más rápidas y se encuentran dentro del procesador. Almacenan datos e instrucciones que están siendo procesados en el momento. Su capacidad es muy limitada.  

2. **Memoria Caché**:  
   Una memoria intermedia que almacena temporalmente datos e instrucciones a los que el procesador accede con frecuencia. Reduce el tiempo de acceso a la memoria principal.  

3. **Memoria Principal (RAM)**:  
   Es la memoria en la que se cargan los programas y datos durante su ejecución. Es volátil, lo que significa que pierde su contenido al apagar el sistema.  

4. **Memoria Secundaria (Discos HDD/SSD)**:  
   Almacenan datos de manera permanente, como el sistema operativo, aplicaciones y archivos. Aunque son más lentas que la RAM, ofrecen mayor capacidad de almacenamiento.  

5. **Almacenamiento Externo (Dispositivos USB, discos externos, etc.)**:  
   Proporcionan almacenamiento adicional y son más lentos que la memoria secundaria.  

6. **Almacenamiento en la Nube**:  
   Datos almacenados en servidores remotos a los que se accede a través de redes. Aunque ofrece gran capacidad y accesibilidad, su velocidad depende de la conexión de red.  

#### Funcionamiento de la Jerarquía de Memoria  
El principio básico de la jerarquía de memoria es que los datos e instrucciones más utilizados deben estar lo más cerca posible del procesador para minimizar el tiempo de acceso. Esto se logra mediante un sistema de almacenamiento en niveles:  

1. **Localidad Temporal**: Los datos que se han utilizado recientemente tienen más probabilidades de ser utilizados nuevamente en un futuro cercano. Estos datos suelen almacenarse en la memoria caché.  

2. **Localidad Espacial**: Los datos cercanos a otros que han sido accedidos recientemente tienen más probabilidades de ser utilizados. Por ello, los sistemas precargan bloques de datos en la memoria desde los niveles inferiores hacia los superiores.  

Cuando el procesador necesita un dato, primero lo busca en los niveles superiores de la jerarquía (como la caché). Si no se encuentra allí, busca en los niveles inferiores, lo que implica un mayor tiempo de acceso.  

#### Propósito del Proyecto  
En este repositorio, se incluyen proyectos y prácticas que exploran el manejo de recursos en sistemas operativos, como la gestión de memoria, la sincronización de procesos y el uso eficiente de la jerarquía de memoria. Estas actividades no solo refuerzan el conocimiento teórico, sino que también brindan experiencia práctica al implementar y analizar conceptos esenciales para la ingeniería de sistemas.  

Espero que este repositorio sea útil para entender mejor el impacto de los sistemas operativos en el rendimiento de las aplicaciones y en el uso eficiente de los recursos del sistema. ¡Gracias por visitar!  
