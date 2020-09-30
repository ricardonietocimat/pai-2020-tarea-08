# Programación y Algoritmos I : Tarea 08 -- Montículos ternarios

**Nota 1:** Esta tarea es *colaborativa* (en pares y con un repositorio git). Un medio punto
se atribuirá en función del buen uso de git entre ambos participantes (contribuciones equilibradas y revisiones
de uno para el otro). 

**Nota 2:** Se atribuirá otro medio punto en la elaboración de tests (por ejemplo con las funciones *assert*); 
la idea es que cada uno en el euqipo pruebe (con tests) la robustez del código del otro.

En la clase, vimos la estructura de montículo binario. Nos permite, entre otras aplicaciones, 
implementar de forma eficiente colas de prioridad o ordenar datos. 
En esta tarea, nos vamos a enfocar en una estructura
muy similar, el montículo ternario. Como su nombre lo indica, se trata de una estructura basada en un
árbol ternario, en lugar de binario. Significa que cada nodo de este árbol (excepto para los nodos hojas)
tiene exactamente tres hijos.
Un montículo ternario cumple con las propriedades de los montículos: 
* el árbol ternario correspondiente está casi completo
* las raíces de cualquier sub-árbol contienen una llave superior a todas las de los otros
nodos del sub-´arbol. 

En la figura siguiente, damos un ejemplo de montículo ternario.

Es interesante observar que, de manera similar a lo que vimos en la clase con montículos binarios, se
puede implementar esta estructura con un arreglo, guardando los datos nivel por nivel. Con el primer
dato en el índice 0, se puede mostrar que los tres hijos del nodo ubicado en el índex k se encuentran en
los índices 3k + 1, 3k + 2, 3k + 3; similarmente, el padre del nodo de índex k se encuentra en el índex
(k − 1)/3.

