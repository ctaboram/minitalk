# minitalk

El objetivo de este proyecto es implementar una comunicación entre procesos en Linux utilizando señales (SIGUSR1 y SIGUSR2). El proyecto consta de dos programas: un servidor y un cliente. El cliente envía mensajes al servidor, carácter por carácter, usando solo señales del sistema.

## Compilación

Para compilar el proyecto, ejecuta:

```bash
make
```

Esto generará los ejecutables `server` y `client`.

## Uso

Primero, inicia el servidor en una terminal:

```bash
./server
```

El servidor mostrará su PID (identificador de proceso), por ejemplo:

```
Server PID: 12345
```

Luego, en otra terminal, ejecuta el cliente pasando el PID del servidor y el mensaje que deseas enviar:

```bash
./client 12345 "Hola, mundo"
```

El mensaje aparecerá en la terminal del servidor.

## Descripción

- Comunicación entre procesos usando únicamente señales (SIGUSR1 y SIGUSR2).
- El cliente envía los caracteres del mensaje uno a uno al servidor.
- El servidor reconstruye el mensaje y lo muestra por pantalla.

## Estado del proyecto

Proyecto terminado.

---
