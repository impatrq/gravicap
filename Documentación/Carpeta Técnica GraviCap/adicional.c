BaseType_t xTaskCreate( 
    TaskFunction_t pvTaskCode, // Puntero a la funcion que implementa la tarea 
    const char * const pcName, // Nombre descriptivo de la tarea (para depuracion) 
    const configSTACK_DEPTH_TYPE usStackDepth, // Espacio reservado 
    void * const pvParameters, // Puntero a parametros para la tarea (puede ser NULL) 
    UBaseType_t uxPriority, // Prioridad de la tarea 
    TaskHandle_t * const pxCreatedTask // Handle de la tarea creada (puede ser NULL)
);