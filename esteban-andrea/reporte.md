# Tarea 08
## Implementación

### Pregunta 01
El montículo se implementó en `heap.c` de la carpeta `Esteban-Andrea` y las pruebas están en `specs.h`

### Pregunta 02
La complejidad de cada función se comentó en el código.

## Aplicación 

### Pregunta 03
la mediana en streaming se implementó en `median.c` de la carpeta `Esteban-Andrea` y las pruebas están en `specs.h`
La idea fue utilizar un apuntador a funciones en las funciones ya implementadas de `heap.c` para ordenar los datos como lo pide el problema.

### Pregunta 04
Demostrar que el algoritmo propuesto calcula bien el valor mediano.  
**Demostración**. Sea n el número actual de datos y {m} su mediana. Supongamos que se tiene un montículo `th_max` y `th_min` que guardan los elementos como se describe en el enunciado y supongamos que⋅⋅

<img src="https://latex.codecogs.com/gif.latex?|size(th\_mx)&space;-&space;size(th\_min)|&space;\leq&space;1" title="|size(th\_mx) - size(th\_min)| \leq 1" />

Así que podemos dividir este problema en dos casos. Sea <img src="https://latex.codecogs.com/gif.latex?d' " title="d' " /> un nuevo dato introducido
* Caso 1. Si <img src="https://latex.codecogs.com/gif.latex?n" title="n" /> es impar. Entonces la mediana será alguno de los valores de la raíz de los montículos. Será el montículo que tenga un elemento más.
Si `th_max` tiene más elementos, entonces la mediana de los datos será su raíz, luego <img src="https://latex.codecogs.com/gif.latex?d'" title="d'" /> se compara con esta raíz.   Notemos que como pedimos que la diferencia entre los tamaños de los árboles sea a lo más uno, la cantidad de datos que tengamos ahora será par.
Si d'<m entonces d' se debe insertar en th_max (ya que corresponde a un elemento pequeño) pero esto rompería con la propiedad que se le pide a los tamaños.
Así que se quita la raíz de `th_max` y se inserta ahora en `th_min` ( pues ahora corresponde a los datos más grandes) y <img src="https://latex.codecogs.com/gif.latex?d' " title="d' " /> se inserta en `th_max`.  
Si <img src="https://latex.codecogs.com/gif.latex?d'>m" title="d'>m" /> entonces corresponde a un dato "grande" por lo que se inserta en `th_min` y se sigue cumpliendo la propiedad del tamaño de los montículos.  
Si `th_max` tiene un elemento menos que `th_min`, entonces el valor de la mediana está en la raíz de `th_min` y se hará algo análogo al subcaso anterior solo que ahora se revisará primero si <img src="https://latex.codecogs.com/gif.latex?d'>m" title="d'>m" />.  
En cualquiera de los subcasos anteriores, ahora el número de datos es par y en consecuencia, los montículos tendrán la misma cantidad de elementos, por lo que la mediana será 
el promedio de las raíces.  

* Caso 2. <img src="https://latex.codecogs.com/gif.latex?n" title="n" /> es par. Sean <img src="https://latex.codecogs.com/gif.latex?x" title="x" /> y <img src="https://latex.codecogs.com/gif.latex?y" title="y" /> las raíces de `th_max` y `th_min`, entonces la mediana será  
<img src="https://latex.codecogs.com/gif.latex?m&space;=&space;\frac{x&plus;y}{2}" title="m = \frac{x+y}{2}" />.  
Notemos que  <img src="https://latex.codecogs.com/gif.latex?m&space;=&space;\frac{x&plus;y}{2}&space;<=&space;\frac{y&plus;y}{2}&space;=&space;y" title="m = \frac{x+y}{2} <= \frac{y+y}{2} = y" /> y <img src="https://latex.codecogs.com/gif.latex?m&space;=&space;\frac{x&plus;y}{2}&space;>=&space;\frac{x&plus;x}{2}&space;=&space;x" title="m = \frac{x+y}{2} >= \frac{x+x}{2} = x" /> entonces si <img src="https://latex.codecogs.com/gif.latex?x&space;\neq&space;y" title="x \neq y" /> ,  la mediana cumple con  
<img src="https://latex.codecogs.com/gif.latex?x&space;<&space;m&space;<&space;y" title="x < m < y" />.  
Si insertamos un nuevo dato <img src="http://latex.codecogs.com/svg.latex?d'" title="http://latex.codecogs.com/svg.latex?d'" /> entonces podrían pasar, de nuevo, dos cosas  
si <img src="http://latex.codecogs.com/svg.latex?d'<&space;m&space;<&space;y" title="http://latex.codecogs.com/svg.latex?d'< m < y" /> entonces este dato está en la mitad más pequeña de los datos, por lo que se debe insertar en `th_max`, como ahora los montículos tienen el mismo tamaño, solo se inserta en `th_max`.   
Ahora tendremos una cantidad impar de datos pero como este nuevo dato es menor que la mediana, la nueva mediana debe ser la raíz de `th_max`, es decir, la nueva mediana es el máximo del montículo max.
Si <img src="https://latex.codecogs.com/gif.latex?d'>&space;m&space;>&space;x" title="d' > m > x" /> entonces este dato cooresponde a los datos más grandes, por lo que se debe insertar en `th_min` y , de nuevo, como ahora los montículos tienen el mismo tamaño,
solo se inserta en `th_min`. De nuevo, tendremos una cantidad impar de datos y como el nuevo dato es de la mitad más grande, la nueva mediana será la raíz de `th_min`, es decir, 
el mínimo de `th_min`.  

### Pregunta 05
La complejidad de cada función se comentó en el código.