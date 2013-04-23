/*
    Author: Guillermo Bielsa.
 
 */


#include "pitches.h" //sounds 

// Give name to all LEDs from pin 10 to 13

int led0 = 10;
int led1 = 11;
int led2 = 12;
int led3 = 13;

//Give name to all buttons from pin 0 to 3

int button0 = 0;
int button1 = 1;
int button2 = 2;
int button3 = 3;

//Give name to the speaker (pin 8)

int speaker = 8;


// the setup routine runs once when you press reset:
void setup() {                

  // initialize the digital pin as an output.
  pinMode(led0, OUTPUT);   
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT); 

  //initialize buttons as input.
  pinMode(button0, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

}

// the loop routine runs over and over again forever:
void loop() {

  WelcomeLight();

  int SIZE = 25;
  int sequence[SIZE];

  while(1)
  {
    
    
    //First we make the random sequence (values from 0 to 3)
    
    randomSeed(analogRead(6));    
    for(int j=0; j < SIZE; j++)
    {
      sequence[j] = random(0, 4);

    }



    //Now, the game starts

    int led = 0;
    int seq = 0;
    int reading = 1;

    while (seq == 0)
    {

      showsequence(sequence, reading);

      seq = readsequence(sequence, reading, led);

      if (seq == 0) //well done
      {
        reading ++;
      }
    }
  }


}


//The method WelcomeLight() just makes a sequence of lights and sounds
void WelcomeLight() 
{

  int i = 0;
  for (i=0; i <4; i++)
  {
    tone(speaker, NOTE_A3);
    digitalWrite(led0, HIGH);  
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    delay(200);             

    tone(speaker, NOTE_B3);
    digitalWrite(led0, LOW);  
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    delay(200);

    tone(speaker, NOTE_C3);
    digitalWrite(led0, LOW);  
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);

    delay(200);    

    tone(speaker, NOTE_D3);
    digitalWrite(led0, LOW);  
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);

    delay(200);

  }

  for (i=0; i <3; i++)
  {
    
    tone(speaker, NOTE_F3);
    
    digitalWrite(led0, HIGH);  
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);

    delay(100);
    
    noTone(speaker);

    digitalWrite(led0, LOW);  
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    delay(100);
    noTone(speaker);
  }
  delay(200);

}



//The method FailLight() just makes a sequence of lights and sounds
void FailLight()
{

    tone(speaker, NOTE_G3);
    
    digitalWrite(led0, LOW);  
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);

    delay(200);    

    tone(speaker, NOTE_F3);
    
    digitalWrite(led0, LOW);  
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);

    delay(200);    
    
    tone(speaker, NOTE_E3);
    
    digitalWrite(led0, LOW);  
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);

    delay(200);    
    
    tone(speaker, NOTE_D3);

    digitalWrite(led0, HIGH);  
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    
    delay(200);
    
  

  for (int i=0; i <3; i++)
  {
    tone(speaker, NOTE_A2);
    
    digitalWrite(led0, HIGH);  
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);

    delay(100);

    noTone(speaker);
    
    digitalWrite(led0, LOW);  
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    delay(100);
  }
  delay(200);

}


//Method that returns the pushed button identification
int ReadButton()
{
  
  button0 = digitalRead(0);
  button1 = digitalRead(1);
  button2 = digitalRead(2);
  button3 = digitalRead(3);

  if(button0 == LOW)
  {
    digitalWrite(led0, HIGH);
    tone(speaker, NOTE_E4);
    delay(200);
    noTone(speaker); 
    digitalWrite(led0, LOW);
    return 0;
  }

  if(button1 == LOW)
  {
    digitalWrite(led1, HIGH);
    tone(speaker, NOTE_A4);
    delay(200);
    noTone(speaker); 
    digitalWrite(led1, LOW);
    return 1;
  }


  if(button2 == LOW)
  {
    digitalWrite(led2, HIGH);
    tone(speaker, NOTE_D4);
    delay(200);
    noTone(speaker); 
    digitalWrite(led2, LOW);
    return 2;
  }


  if(button3 == LOW)
  {
    digitalWrite(led3, HIGH );
    tone(speaker, NOTE_G4);
    delay(200);
    noTone(speaker); 
    digitalWrite(led3, LOW);
    return 3;
  }

  else
  {
    return -1;
  }

}


//Method that shows the current sequence (until 'count') with lights and sounds
void showsequence (int array[],int counts)
{

  int i = 0;
  while(i < counts)
  {
    int led = array[i];
    int delayvalue = 500 - (3 * counts);
    switch (led)
    {
    case 0:
      digitalWrite(led0, HIGH); 
      tone(speaker, NOTE_E4);
      delay(delayvalue);
      noTone(speaker); 
      digitalWrite(led0, LOW); 
      delay(delayvalue/2);
      i++;
      break;

    case 1:
      digitalWrite(led1, HIGH); 
      tone(speaker, NOTE_A4);
      delay(delayvalue);
      noTone(speaker); 
      digitalWrite(led1, LOW); 
      delay(delayvalue/2);
      i++;
      break;

    case 2:
      digitalWrite(led2, HIGH); 
      tone(speaker, NOTE_D4);
      delay(delayvalue);
      noTone(speaker); 
      digitalWrite(led2, LOW); 
      delay(delayvalue/2);
      i++;
      break;

    case 3:
      digitalWrite(led3, HIGH); 
      tone(speaker, NOTE_G4);
      delay(delayvalue);
      noTone(speaker); 
      digitalWrite(led3, LOW); 
      delay(delayvalue/2);
      i++;
      break;
    }
  }

}


//Method that compares the random sequence with the pushed buttons
int readsequence(int seq[], int current, int led)
{

  int i = 0;
  while(i < current)
  {
    int button = ReadButton();


    if(button != seq[i] && button != -1) //Keep trying (game ends)
    {
      FailLight();
      return -1;
    }

    if(button == seq[i])  //Nice good job (game continues)
    {
      i++;
    }



  }

  delay(250);
  return 0;
}



