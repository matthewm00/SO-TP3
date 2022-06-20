# SO-TP3

Réplica del comportamiento del binario _server_ con desafíos resueltos con ingeniería inversa para la materia Sistemas Operativos

<hr>

## Autores

- Nicole Hinojo Toré
- Santiago Larroude
- Mateo Menghini

## Compilación

Ejecutar `make` o `make all` para el compilado de los archivos.

Si desea removerlos, ejecute `make clean` en el mismo directorio donde fue realizada la compilación.

## Ejecución

Para correr el programa, ejecutar el archivo **server** corriendo `./server` y en tra terminal conectada al mismo contenedor de Docker, ejecutar el archivo **client** corriendo `./client` para poder jugar a los desafíos.

## Testeo

Para el testeo con **PVS-Studio**, **Cppcheck** y **Valgrind** se debe primero instalar **PVS-Studio**.

Instalarlo de la siguiente manera en su contenedor de _docker_.

```bash
apt-get update
apt-get install pvs-studio
pvs-studio-analyzer credentials "PVS-Studio Free" "FREE-FREE-FREE-FREE"
```

Luego correr el siguiente comando:

```bash
 make test
```

Los resultados se encontrarán en los siguientes archivos:

- **PVS-Studio:** report.tasks
- **Valgrind:** results.valgrind
- **Cppcheck:** output.txt

Para borrar los archivos, correr el comando `make cleanTest` en el mismo directorio donde fue realizada la compilación.
