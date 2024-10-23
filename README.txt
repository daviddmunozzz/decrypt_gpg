Realizado por David Muñoz Escribano

Para averigüar la contraseña lo primero que se debe hacer es crear un diccionario con el script 'create_dictionary.py'. Este programa
realiza todas las combinaciones con repetición posibles de la 'a' a la 'z', el parámetro que se debe modificar es la cantidad de 
caracteres que tiene la contraseña. Por defecto está acotado a 4 caracteres.
Ejecución del script:
`python3 create_dictionary.py`
Salida: `dictionary.txt`

Una vez creado el diccionario de posibles contraseñas se llevará a cabo la ejecución del descifrador `decrypt.cpp`. Está desarrollado 
con OpenMP para agilizar el proceso de descifrado con múltiples hilos. En mi caso utilizo 8 hilos pues mi equipo dispone de 8 hilos lógicos,
es un parámetro modificable dependiendo del equipo. El programa dispone de ejecución silenciosa si se quisiera, mostrando solo
la contraseña y el tiempo transcurrido, para hacer ésto se necesitaría descomentar la variable `command_sil` y ejecutarla en el método
system.
La solución al problema se realiza mediante fuerza bruta, probando con todas las combinaciones del diccionario.
Compilación:
`g++ -fopenmp decrypt.cpp -o <nombre_ejecutable>`
Ejecución:
`./<nombre_ejecutable>`
Salida:
`Passphrase: <contraseña>
 Time: <Tiempo en horas>`



