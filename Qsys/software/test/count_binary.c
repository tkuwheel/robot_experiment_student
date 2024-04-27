#include <stdio.h>
#include <system.h>
#include <io.h>
#include <unistd.h>

int main()
{
  int bt,led,i;
  led=0x02;
  printf("test\n");
  while(1){
	  bt=IORD(BUTTON_BASE, 3);
	  if(bt==2){
		  IOWR(BUTTON_BASE, 3, 0);
		  printf("%d\n",bt);
		  for(i=0;i<5;i++){
			  IOWR(LED_BASE, 0, led);
			  usleep(100000);
			  led = led << 2;
			  if(led > 0x200){
				  led = 0x100;
				  break;
			  }
		  }
		  for(i=0;i<5;i++){
			  IOWR(LED_BASE, 0, led);
			  usleep(100000);
			  led = led >> 2;
			  if(led < 0x01){
				  led = 0x02;
				  break;
			  }
		  }
	  }
  }
  return 0;
}
