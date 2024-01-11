String data;
void setup()
{
  pinMode(6, OUTPUT);//1
  pinMode(7, OUTPUT);//2
  pinMode(3, OUTPUT);//3
  pinMode(2, OUTPUT);//4
  pinMode(11, OUTPUT);//redleft
  pinMode(12, OUTPUT);//blueleft
  pinMode(13, OUTPUT);//greenleft
  pinMode(8, OUTPUT);//redright
  pinMode(9, OUTPUT);//blueright
  pinMode(10, OUTPUT);//greenright
  pinMode(4, OUTPUT);//horn
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available())
  {
    data=Serial.readString();
    Serial.println(data);
    
    
    if(data == " ")
    {
      Serial.println("give the coomand");
    }
    
    
    //BACKWARD
    
    
    else if(data=="back")
    {
      //ANTICLOCK
      analogWrite(5,55);
  	  analogWrite(9,55);
      digitalWrite(6,1); 
  	  digitalWrite(7,0);
      digitalWrite(3,1); 
  	  digitalWrite(2,0);
  	  delay(3);
      Serial.println("moving back");     
      digitalWrite(4,1);   
      redlightsblink();
      
    }
    
    
    //FARWARD
    
    
    
    else if(data=="front")
    {
  		//CLOCK
        analogWrite(5,55);
  	    analogWrite(9,55);
      	analogWrite(8,0);
    	analogWrite(A3,0);
    	analogWrite(10,0); 
      	analogWrite(11,0);
    	analogWrite(12,0);
    	analogWrite(13,0); 
  		digitalWrite(6,0); 
  		digitalWrite(7,1);
        digitalWrite(3,0); 
  		digitalWrite(2,1);
  		delay(3);
        Serial.println("moving front");
      digitalWrite(4,0);
    }
    
    
    
    //STOP
    
    
    
    else if(data=="stop")
    {
  		//STOP
      	analogWrite(8,255);
    	analogWrite(A3,0);
    	analogWrite(10,0); 
      	analogWrite(11,255);
    	analogWrite(12,0);
    	analogWrite(13,0); 
  		digitalWrite(6,0); 
  		digitalWrite(7,0);
        digitalWrite(3,0); 
  		digitalWrite(2,0);
  		delay(3);
        Serial.println("not moving ");
      digitalWrite(4,0);
    }
    
    //speed
    else if(data=="speed")
    {
      delay(3000);
       if(Serial.available())
  			{
    			int speed=Serial.parseInt();
    			Serial.println(speed);  
  				analogWrite(5,speed);
  				analogWrite(9,speed);
  			}
      else{
        		analogWrite(5,255);
  				analogWrite(9,255);
           }    
     }
    
    //RIGHTWAERD
    
    
    
    else if(data=="right")
    {
      //CLOCK
      analogWrite(5,55);
  	  analogWrite(9,55);
      digitalWrite(6,0); 
  	  digitalWrite(7,1);
      digitalWrite(3,0); 
  	  digitalWrite(2,0);
  	  delay(3);
      Serial.println("moving right");  		
      rightyellowlightblink();
      digitalWrite(4,0);
  	  
    }
    
    
    
    //LEFTWARD
    
    
    
    else if(data=="left")
    {
      //antiCLOCK
      analogWrite(5,55);
  	  analogWrite(9,55);
      digitalWrite(6,0); 
  	  digitalWrite(7,0);
      digitalWrite(3,1); 
  	  digitalWrite(2,0);
  	  delay(3);
      Serial.println("moving left");       		
      leftyellowlightblink();
      digitalWrite(4,0);
  	  
    }
    
    
    
    //BACKRIGHT
    
    
    
    else if(data=="backright")
    {
      //ANTICLOCK
      analogWrite(5,55);
  	  analogWrite(9,55);
      digitalWrite(6,1); 
  	  digitalWrite(7,0);
      digitalWrite(3,0); 
  	  digitalWrite(2,0);
  	  delay(3);
      Serial.println("moving backright");  
      rightredlightblink();
      digitalWrite(4,1);
    }
    
    
    
    //BACKLEFT
    
    
    
    else if(data=="backleft")
    {
      //ANTICLOCK
        analogWrite(5,55);
  	    analogWrite(9,55);
      	digitalWrite(6,0); 
  		digitalWrite(7,0);
        digitalWrite(3,1); 
  		digitalWrite(2,0);
  		delay(3);
        Serial.println("moving backleft");      
        leftredlightblink();
        digitalWrite(4,1);
    }
    
    
    //HORN
    
    else if (data=="horn") 
    {
    tone(4, 440,2000); // play tone 57 (A4 = 440 Hz)
    }
    else if (data=="hornoff") 
    {
    tone(4, 0,2000); // play tone 57 (A4 = 440 Hz)
    }
    
    
    
    //HEADLIGHTON
    
    else if (data=="headlight") 
    {
      
    	analogWrite(A2,230);
    	analogWrite(A0,33);
    	analogWrite(A1,219);
    }
    //HEADLIGHTOFF
    
    else if (data=="headlightoff") 
    {
    	analogWrite(A2,0);
    	analogWrite(A0,0);
    	analogWrite(A1,0);
    }
    
    
     else 
    {
        digitalWrite(6,1); 
  		digitalWrite(7,1);
        digitalWrite(3,1); 
  		digitalWrite(2,1);
  		delay(3);
        Serial.println("give the correct command");
      
    }
     
 }
}

void redlightsblink()
{ 
  
  
      	for(int i=0;i<=255;i=i+1)
       	{
    		analogWrite(8,i);
    		analogWrite(A3,0);
    		analogWrite(10,0); 
      		analogWrite(11,i);
    		analogWrite(12,0);
    		analogWrite(13,0);
        	delay(1);
          	
  		}
 }



void rightyellowlightblink()
{
  
  
        for(int i=0;i<=255;i=i+1)
        {
    		analogWrite(8,230);
    		analogWrite(A3,33);
    		analogWrite(10,219); 
      		analogWrite(11,0);
    		analogWrite(12,0);
    		analogWrite(13,0);
        	delay(10);
  		}   
  		
   
  
  
}


void leftyellowlightblink()
{
  
        for(int i=0;i<=255;i=i+1)
        {
    		analogWrite(8,0);
    		analogWrite(A3,0);
    		analogWrite(10,0); 
      		analogWrite(11,230);
    		analogWrite(12,33);
    		analogWrite(13,219);
        	delay(1);
  		}
  		
      
}

void rightredlightblink()
{
   
      	for(int i=0;i<=255;i=i+1)
       	{
    		analogWrite(8,i);
    		analogWrite(A3,0);
    		analogWrite(10,0); 
      		analogWrite(11,0);
    		analogWrite(12,0);
    		analogWrite(13,0);
        	delay(1);
       	}
  		
      
}
void leftredlightblink()
{
  
      	for(int i=0;i<=255;i=i+1)
       	{
    		analogWrite(8,0);
    		analogWrite(A3,0);
    		analogWrite(10,0); 
      		analogWrite(11,i);
    		analogWrite(12,0);
    		analogWrite(13,0);
        	delay(1);
       	}
  		
      
}
