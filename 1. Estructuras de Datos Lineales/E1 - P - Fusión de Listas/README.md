
# Consolidación y Deduplicación de Fuentes de Dato

**Contexto:** En la preparación e integración de conjuntos de datos (datasets) a partir de
múltiples fuentes heterogéneas, es habitual encontrar registros repetidos de una misma
entidad. Para ciertas tareas de análisis, solo se requiere registrar la presencia única de cada
elemento, preservando el orden cronológico o de secuencia en que fueron observados por
primera vez.

### Descripción del Procedimiento

Escriba un programa en C que lea dos flujos de números
enteros positivos ingresados por consola. Cada flujo finaliza con el valor indicador -1. El
programa debe almacenar cada secuencia en una lista independiente y, apoyándose en la
función:
lista fusionarUnicos(lista l1, lista l2)
Construir y retornar una tercera lista que fusione los datos bajo las siguientes reglas
estrictas:

**1. Deduplicación de la primera lista:** Incluir los elementos de la primera lista
conservando únicamente su primera aparición (eliminar duplicados internos).

**2. Inclusión condicional de la segunda lista:** Agregar los elementos de la segunda lista
que no existan en la primera lista (garantizando también que no se repitan entre sí).

**3. Preservación del orden:** Respetar la secuencia relativa de primera aparición de cada
elemento.

Ejemplo:

Input:

4 2 4 8 1 -1

2 5 8 9 -1

Output: 4 2 8 1 5 9

### Especificaciones y restricciones

• **Gestión de memoria:** Una vez impresa la lista resultante en pantalla, el programa debe invocar la función de destrucción/liberación de memoria para las tres listas instanciadas (Lista 1, Lista 2 y Lista Fusionada), garantizando cero fugas de memoria
(memory leaks).

• **Nivel de abstracción:** La función fusionarUnicos y el main deben resolver el
problema utilizando la interfaz pública de su TAD Lista . Se debe evitar manipular
directamente punteros de nodos fuera de las funciones propias de la estructura.

