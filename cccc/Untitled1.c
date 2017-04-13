
void delay() {
  volatile unsigned int j;

  for (j = 0; j < (500000); j++) ;	// delay
}

void _mips_handle_exception(void* ctx, int reason) {
  volatile int *IO_LEDR = (int*)0xbf800000;

  *IO_LEDR = 0x8001;  // Display 0x8001 on LEDs to indicate error state
  while (1) ;
}

int main() {
  volatile int *IO_7SEGEN = (int*)0xb0800000;
  volatile int *IO_7SEG  = (int*)0xb0800004;

  volatile unsigned int count = 0;
  volatile int i=0;
  volatile int tep;
  *IO_7SEGEN = 0;              // enable all
  while (1) {
	*IO_7SEG =0;
	tep=count;
	for(i=0;i<=7;i++){
		*IO_7SEG=*IO_7SEG | (tep<<(4*i));
	}
    delay();
	count=(count+1)%16;
  }
  return 0;
}
