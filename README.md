# Proyecto: Carrito de compras / Administrador de inventario
Daniel Queijeiro Albo A01710441

Este proyecto consiste en desarrollar un programa de consola que se encargue de brindar servicio a clientes y administradores. Para los clientes dar la utilidad de un carrito de compras donde puedan insertar los productos que quieren comprar y recorrer la lista. Para los administradores gestionar el inventario de productos de una tienda.
Utilizando conceptos de estructura de datos y algoritmos se planea darle funcionalidad al proyecto.
Dentro de los conceptos a utilizar destacan:
- Vectores: para almacenar el inventario completo de la tienda
- Listas ligadas: para almacenar los productos del carrito de compras.
- Lectura y escritura de csv: para poder acceder y modificar el archivo originario del inventario de la tienda. 
- Algoritmos de busqueda: para buscar un producto.
- Algoritmos de ordenamiento: para ordenar el inventario de la tienda.

## Descripción del avance 1
En el primer avance se definira lo que se planea que realice el proyecto, se dara formato al README.md, y se empezará a programar las clases.

## Descripción del avance 2
En el segundo avance se completaron las funcionalidades para administrador y cliente. Usando principalmente para las funciones de administrador vectores y para los clientes listas ligadas.

### Cambios sobre el primer avance
- Cambio 1: Originalmente se planeaba usar vectores unicamente, pero al revisar los requisitos del proyecto, se añadieron listas ligadas.
- Cambio 2: Se añadió la funcionalidad del carrito de compra, pues ya había completado las funciones del administrador con vectores y resultaba más facil implementar listas ligadas en nuevas funciones que reemplazar todo lo existente.

## Descripción del avance 3
En el tercer avance se completo la función de lista de compras para que muestre el precio total de la lista. También se agrego la función de crear un archivo txt donde se guarde la información de la compra.

### Cambios sobre el segundo avance
- Cambio 1: Se completo la funcionalidad de la lista de compras para que muestre el costo total de la orden.
- Cambio 2: Se agrego la funcionalidad de crear un archivo txt donde se guarde la información de la compra.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o tercer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./tercer_avance` 

## Descripción de las entradas del avance de proyecto
El proyecto puede recibir un archivo csv o si no existe se creará dicho archivo para con el guardar el inventario a través de manipulación de archivos. Así, el administrador podrá abrir, modificar y guardar el archivo para su uso en un futuro. Y el cliente podrá observar el inventario completo de la tienda para llenar su carrito de compras.

## Descripción de las salidas del avance de proyecto
El resultado de ejecución del programa dependerá de lo que el usuario realice. Si el usuario es un administrador se mostrara en la consola el inventario completo, añadir, eliminar o modificar un producto, buscar un producto. Y si el usuario es un cliente se creara un archivo txt con su carrito de compras con los respectivos productos.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El algoritmo de ordenamiento seleccionado es "Insertion Sort" el cual cuenta con un nivel de complejidad O(n^2).

Y al trabajar con vectores y listas ligadas podemos esperar una complejidad baja.
Dentro del código podemos encontrar varias funciones y metodos, pero en cuanto a complejidad, la función de "Insertion Sort" es la que mayor complejidad tiene, con O(n^2)

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Dentro del proyecto usamos estructuras de datos de vectores y listas ligadas.
Los vectores son estructuras de datos de tipo dinámico que almacenan datos en una secuencia contigua de memoria. Los vectores son eficientes en el acceso a los elementos, ya que el índice de un elemento es simplemente su posición dentro del vector.
- Acceso a un elemento	O(1)
- Inserción de un elemento al final	O(1)
- Inserción de un elemento en una posición determinada	O(n)
- Eliminación de un elemento al final	O(1)
- Eliminación de un elemento en una posición determinada	O(n)
- Búsqueda de un elemento	O(n)

Las listas ligadas son estructuras de datos de tipo dinámico que almacenan datos en una secuencia de nodos. Cada nodo contiene un dato y un puntero al siguiente nodo en la lista. Las listas ligadas son eficientes en la inserción y eliminación de elementos, ya que solo es necesario actualizar los punteros de los nodos afectados.
- Acceso a un elemento	O(n)
- Inserción de un elemento al final	O(1)
- Inserción de un elemento en una posición determinada	O(n)
- Eliminación de un elemento al final	O(1)
- Eliminación de un elemento en una posición determinada	O(n)
- Búsqueda de un elemento	O(n)


#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
El análisis de complejidad de los demas componentes se detalla en los archivos h, antes de la definición de la función junto con un breve resumen de lo que realiza dicha función.

La complejidad final del programa es O(n^2). Esto debido a la complejidad del algoritmo de ordenamiento "Insertion sort", que es la función con mayor complejidad dentro del programa.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Para este proyecto se usará el algoritmo de ordenamiento "Insertion Sort", por su eficiencia* ante otros algoritmos de ordenamiento como "Quick Sort" o "Heap Sort" al momento de ordenar listas de datos de tamaño pequeños.
También, "Insertion Sort" es un algoritmo de ordenamiento in situ, lo que significa que no necesita ninguna memoria adicional para realizar el ordenamiento.

*Chen, Q., & Liu, W. (s. f.). Test and evaluate the performance of sorting methods. Recuperado 27 de septiembre de 2023, de https://www.cse.unr.edu/~chen_q/sorta.html#:~:text=3)%20For%20small%20size%20data,Heapsort%20is%20a%20better%20choice

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Para el uso de vectores destaca:
- Los vectores son muy eficientes en el acceso a los elementos, ya que el índice de un elemento es simplemente su posición dentro del vector. Esto es importante en un administrador de inventario, donde se necesita acceder a los elementos de forma rápida y frecuente.
- Los vectores son también eficientes en la modificación de los elementos, ya que solo es necesario actualizar el valor del elemento en la posición correspondiente.
- Los vectores son muy fáciles de implementar


Para el uso de listas ligadas destaca:
- Cuando un usuario agrega un artículo al carrito, solo es necesario crear un nuevo nodo para el artículo y actualizar el puntero al último nodo.
- Las listas ligadas son relativamente fáciles de implementar.
- Las listas ligadas son muy eficientes en la inserción de elementos, ya que solo es necesario actualizar los punteros de los nodos afectados. Esto es importante en un carrito de compras, donde los usuarios pueden agregar artículos con frecuencia.
- Las listas ligadas son faciles de recorrer con su puntero al siguiente nodo.


### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Los vectores son estructuras de datos de tipo estático, lo que significa que su tamaño se conoce de antemano. Esto hace que la implementación de mecanismos para consultar información de los vectores sea relativamente sencilla.

Las listas ligadas son estructuras de datos de tipo dinámico, lo que significa que su tamaño puede crecer o contraerse de forma dinámica. Esto hace que la implementación de mecanismos para consultar información de las listas ligadas sea más compleja que en el caso de los vectores.

En el caso de nuestro proyecto usamos vectores e indices para la busqueda del producto dentro del inventario.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En el proyecto se cuenta con un csv donde se guarda los valores de los productos de la tienda. Al iniciar el programa se lee el csv y se insertan los productos en un vector donde el administrador podrá agregar, modificar o eliminar los datos. Y los clientes podrán elegir de ese vector productos para agregarlos a una lista ligada para poder recorrerla viendo los datos de sus productos.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Dentro del proyecto se implementan dos mecanismos de escritura de archivos. Una es en la parte de administración donde se pueden añadir, modificar o eliminar los objetos a la venta dentro del csv del sistema. Y el segundo es dentro de la parte del cliente, donde al momento de terminar la lista de compras se crea un archivo txt donde se incluye el nombre y precio de cada objeto seleccionado al igual que el monto total de la compra.