// Write a program to find the gross sallery of an employee
//   conditions are --
//     if he's a male and have more than or equal to 5 years experience then
//     he'll get hra: 15%, ta: 20%, da: 10% and sallery: 40,000

//     if she is female and have more than or equal to 3 years experience then
//     she'll get hra: 10%, ta: 15%, da: 10% and sallery: 40,000


void main(void){
     char gen;
     float hra=0.00, ta=0.00, da=0.00, grossSal=0.00;
     long sallery=40000;
     int exp=0;
     clrscr();

     begin:
     printf("\n\nPlease, Enter your Gender M/F(Male/Female)\n-> ");
     scanf("%c", &gen);

     if(gen == 'M' || gen == 'm' || gen == 'F' || gen == 'f'){
	 if(gen == 'M' || gen == 'm'){
	     askExp:
	     printf("Please, Enter your work experience.\n-> ");
	     scanf("%d", &exp);
	     if(exp>=0 && exp<100){
	       if(exp>=5){
		 hra = (sallery*15)/100;
		 ta = (sallery*20)/100;
		 da = (sallery*10)/100;
	       }
	     }
	     else
	       goto askExp;
	 }
	 else{
	     askExp2:
	     printf("\nWhat's your work experience?(years)\n");
	     scanf("%d",&exp);
	     if(exp>=0 && exp<100){
	       if(exp>=3){
		 hra = (sallery*10)/100;
		 ta = (sallery*15)/100;
		 da = (sallery*10)/100;
	       }
	     }
	     else
	      goto askExp2;
	 }
	 grossSal = sallery + hra + ta + da;

	 // Printing Sallery Informations
	 printf("\n\tYour Sallery is %ld\n", sallery);
	 printf("\t  HRA = %f\n\t  TA = %f\n\t  DA = %f\n\n\tYour Gross Sallery = %f\n\n\n",hra,ta,da,grossSal);
     }
     else{
	 printf("Wrong Input!! Please Enter M for Male or F for Female\n\n");
	 goto begin;
     }
     getch();
}