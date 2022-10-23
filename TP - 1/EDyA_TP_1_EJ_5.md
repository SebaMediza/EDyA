# ***Campos de bits--Grupo 005***	

### **Definición**:
Un campo de bits es un conjunto de bits adyacentes dentro de una palabra entera. 
Con los campos de bit, C++ permite acceder a un número de bits de una palabra entera. Para hacer esto, la palabra se subdivide en campos de bits individuales. Estos campos de bits se definen como miembros de una estructura. Cada campo de bits puede ser accedido individualmente, como cualquier otro miembro de una estructura

### **Aspectos Positivos**:
Los campos de bits proporcionan compatibilidad y acceso a la capacidad correspondiente de ANSI-C. Normalmente, se utilizan en situaciones en las que el almacenamiento en memoria es un elemento preciado o cuando un diseño de estructura debe coincidir con el diseño de un registro de hardware.
	
### **Aspectos Negativos**:
	Los campos de bits tienen ciertas restricciones:
+ Así, no se puede tomar la dirección de una variable campo de bits; 
+ No puede haber arrays de campos de bits; 
+ No se puede solapar fronteras de int; 
+ El operador dirección (&) no se puede aplicar a un campo de bits; 
+ Un puntero no puede acceder a un campo de bits; 
+ Y una función no puede devolver un campo de bits
