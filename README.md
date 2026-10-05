*Este proyecto ha sido creado como parte del currículo de 42 por jbustos-.*
## 📄 Descripción

El proyecto **`ft_printf`** consiste en reimplementar la función original `printf` de la biblioteca `<stdio.h>` de C. El objetivo principal es aprender a manipular **argumentos variables** mediante las macros de `<stdarg.h>` (`va_list`, `va_start`, `va_arg`, `va_end`) y manejar formateo de datos a bajo nivel sin depender de funciones externas de conversión de cadenas.

### Visión General y Funcionalidades
El programa procesa una cadena de formato e imprime caracteres en la salida estándar (`stdout`), convirtiendo los argumentos variables según los siguientes especificadores:

| Especificador | Tipo de argumento | Descripción | Ejemplo de salida |
| :---: | :--- | :--- | :--- |
| `%c` | `int` | Imprime un único carácter (incluyendo el carácter nulo `'\0'`). | `A` |
| `%s` | `char *` | Imprime una cadena de caracteres (maneja `NULL` imprimiendo `(null)`). | `Hola 42` |
| `%p` | `unsigned long` | Imprime la dirección de un puntero en formato hexadecimal minúscula precedido por `0x` (o `(nil)` si es nulo). | `0x7ffeefbff5c0` |
| `%d` / `%i` | `int` | Imprime un entero con signo en base 10. | `-2147483648` |
| `%u` | `unsigned int` | Imprime un entero sin signo en base 10. | `4294967295` |
| `%x` | `unsigned int` | Imprime un entero sin signo en base 16 (hexadecimal minúsculas). | `2a` |
| `%X` | `unsigned int` | Imprime un entero sin signo en base 16 (hexadecimal mayúsculas). | `2A` |
| `%%` | N/A | Imprime el símbolo de porcentaje literal. | `%` |

---

## 📐 Elección y Justificación del Algoritmo y Estructura de Datos

### 1. Estructura de Datos: La Pila de Llamadas (*Call Stack*) frente a `malloc`
* **Elección**: Se prescindió por completo del uso de memoria dinámica (`malloc` / `free`) y de la estructura auxiliar típica basada en `ft_itoa`. En su lugar, el estado se mantiene directamente en la **pila de llamadas del sistema** (*Call Stack*) mediante recursividad.
* **Justificación**:
  - **Seguridad de memoria**: Al no reservar memoria dinámica en el *heap*, se elimina al 100% el riesgo de fugas de memoria (*memory leaks*) en cualquier caso de fallo o condición límite.
  - **Eficiencia y restricciones de 42**: Evita sobrecargar el código con verificaciones de punteros nulos tras `malloc`, lo que permite cumplir de forma limpia la regla de **máximo 25 líneas por función** impuesta por la Norminette.

### 2. Justificación de Algoritmos

* **Conversión Numérica y Hexadecimal Recursiva (División Sucesiva)**:
  - **Mecanismo**: Las conversiones de base 10 (`%d`, `%i`, `%u`) y base 16 (`%x`, `%X`, `%p`) utilizan el algoritmo de **división y módulo sucesivo** mediante llamadas recursivas.
  - **Proceso**: Cada llamada divide el número por la base (`/ 10` o `/ 16`) hasta alcanzar el caso base (`n < base`). Al retornar de la recursividad, se escribe el dígito correspondiente (`n % base`) de izquierda a derecha.
  - **Ventaja en `%p`**: La función hexadecimal única se parametriza aceptando tipos de 64 bits (`unsigned long`), permitiendo reutilizar exactamente la misma lógica recursiva para enteros simples de 32 bits y direcciones de memoria de 64 bits sin pérdida de datos (*truncamiento*).

* **Acumulación de Retorno (Conteo de Bytes)**:
  - Todas las funciones internas devuelven un `int` con el recuento exacto de caracteres impresos en pantalla (`write(1, ..., 1)`). Al encadenar estas llamadas, `ft_printf` retorna la cantidad exacta de bytes escritos, cumpliendo de forma idéntica con el estándar de POSIX.

---

## 🛠️ Instrucciones

### Prerrequisitos
Un entorno Unix/Linux con el compilador `gcc` (o `clang`) y la herramienta `make`.

### Compilación e Instalación
Para generar la librería estática `libftprintf.a`, ejecuta en la raíz del repositorio:

```bash
make