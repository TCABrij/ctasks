// --- Program ---
// Calculate electricity bill


void main(void){

    char residence, consumption; // (h - high, m - mid, l - low)
    long units, extraUnits=0;
    int freeUnits = 200, highUnits=0, midBill;
    double bill=0.0, tax=0.0;

    askResidence:
    clrscr();
    printf("Enter your residence: \n  R for Rural \n  U for Urban\n");
    residence=getch();

    if(residence == 'R' || residence == 'r' || residence == 'U' || residence == 'u')
    {
      askunits:
      printf("\nEnter no. of units consumed\n");
      units = get_int();
      if(units>=0)
      {
	 //For Rural People
	 if(residence == 'R' || residence == 'r')
	 {
	    if(units<=freeUnits)
	    {
	      bill = 100;
	      consumption = 'l';
	    }
	    else if(units>freeUnits && units<=400)
	    {
	     // 5rs per unit on extra units
	      extraUnits = units-freeUnits;
	      bill = extraUnits*5;
	      consumption = 'm';
	    }
	    else // for greater than 400 units
	    {
	      // Substracting unit which is free
	      extraUnits = units - freeUnits;

	      // 5rs per unit on 201 to 400
	      midBill = 199*5;

	      // 7rs per unit on rest units
	      highUnits = extraUnits-199;
	      bill = highUnits*7;

	      // Tax because of high consumption
	      tax = (bill/5);  // 20%
	      bill = bill + midBill + tax;
	    }
	 } // For Urban People
	 else
	 {
	   freeUnits = 100;
	   if(units<=freeUnits)
	    {
	      bill = 100;
	      consumption = 'l';
	    }
	    else if(units>freeUnits && units<=400)
	    {
	     // 7rs per unit on extra units
	      extraUnits = units-freeUnits;
	      bill = extraUnits*7;
	      consumption = 'm';
	    }
	    else // for greater than 400 units
	    {
	      // Substracting unit which is free
	      extraUnits = units - freeUnits;

	      // 7rs per unit on 101 to 400
	      midBill = 299*7;

	      // 9rs per unit on rest units
	      highUnits = extraUnits-299;
	      bill = highUnits*9;

	      // Tax because of high consumption
	      tax = (bill*2)/5;  // 40% Tax
	      bill = bill + midBill + tax;
	    }
	 }
	 // Start Printing Bill Details
	 clrscr();
	 if(residence=='R' || residence=='r')
	    printf("\nResidence -> RURAL");
	 else
	    printf("\nResidence -> URBAN");
	 printf("\nConsumed Units -> %ld",units);
	 if(consumption == 'l')
	   printf("\n -> Great consumption of Electricity! ");
	 else if(consumption == 'm')
	 {
	   printf("\n -> Good consumption of Electricity!");
	   printf("\nChargable Units: %ld",extraUnits);
	 }
	 else
	 {
	   printf("\n ->High consumption of Electricity!!");
	   printf("\nChargable Units: %ld\nHight Units: %d",extraUnits,highUnits);
	   printf("\nTax on High uses: %lfRs",tax);
	 }
	 printf("\n\nBill: %lfRs",bill);
	// ^End Printing Bill details
      }
      else
      {
       printf("Invalid input!!");
       getch();
       goto askunits;
      }
    }
    else{
	printf("Invalid input");
	getch();
	goto askResidence;
    }
    getch();
}


  // Function to get valid integer from user

 int get_int()
 {
   char ch;
   long number=0, count=0;
   while(1)
   {
     ch=getche();
     if(ch>=48 && ch<=57)
       number = (number*10)+(ch-48);
     else if(ch!=13)
       count++;

     if(ch==13)
     {
       if(count>0)
	 return -1;
       return number;
     }
   }

 }

