#include "FreeRTOS.h"
#include "task.h"


#include "LED.h"
#include "DIO.h"

void LED_init(void);
void LED_ON(void);

int main(void)
{

	                 /* Example to create task
	                  *
	 * BaseType_t xTaskCreate(    TaskFunction_t pvTaskCode,
		                            const char * const pcName,
		                            configSTACK_DEPTH_TYPE usStackDepth,
		                            void *pvParameters,
		                            UBaseType_t uxPriority,
		                            TaskHandle_t *pxCreatedTask
		                          );
		                          */

	 xTaskCreate(LED_init,"init",100,NULL,1,NULL);

	 xTaskCreate(LED_ON,"on",100,NULL,1,NULL);





	/* Start Scheduler */
	vTaskStartScheduler();

	while(1)
	{

	}
}

/*****************************************************************************************************/
/*****************************************************************************************************/
/* task to init the DIO driver for one time
 * after init it will be susbended
 */

void LED_init(void)
{
	DIO_init();
	vTaskSuspend(NULL);
	while(1){}

}


/*****************************************************************************************************/
/*****************************************************************************************************/

/* task to toggle the led every one second*/

void LED_ON(void)
{
	while(1)
	{
		LED_toggle();
		vTaskDelay(1000);

	}
}
