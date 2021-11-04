#include <bmps.h>
#include<PCD8544_HOANGSA.h>
#include <avr/interrupt.h>

#define RST 2     // lcd nokia is screen
#define CE 3
#define DC 4
#define DIN 5
#define CLK 6

#define UP A3       //button to click
#define DOWN A6
#define RIGHT A4
#define LEFT A7
#define OK A5

#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262

PCD8544 lcd (RST, CE, DC, DIN, CLK);
//----------For Snake_Xenzia----------------------
typedef struct
{
  int stt;
  int x;
  int y;
} snake;            // A block of snake
int size = 2;       // a block has size 3x3 pixel

snake snakes[100], new_pos;  // Max len is 100

int prey_x = random(0, 84 / size);
int prey_y = random(0, 48 / size);
int direct = 1;
//bool _loading = true;
bool start_game = true;
int level_of_difficult;
int status_computer = 0;
//--------------------------------------------------
int score = 0;
volatile bool snake_eat_prey = false;
int dem = 0;



void setup()
{
  lcd.ON();
  lcd.SET(50, 0, 0, 0, 4); // contrast and bias
  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  //Timer 1
//  cli(); //tắt ngắt toàn cục
//  TCCR1A = 0;
//  TCCR1B = 0;
//  TIMSK1 = 0;
//  TCCR1B |= (1 << CS11) | (1 << CS10); //setup timer 1 prescale = 64
//  TIMSK1 = (1 << TOIE1);
//  sei();
  setup_snake();
}

void loop()
{
  if (status_computer == 0)
  {
    static bool main_loading = true;
    if (main_loading)
    {
      loading();
      lcd.Clear();
      lcd.Display();
      main_loading = false;
    }
    main_menu();
  }
  if (status_computer == 1)
  {
    if (start_game)
    {
      static bool level_loading = true;
      if (level_loading)
      {
        loading();
        lcd.Clear();
        lcd.Display();
        level_loading = false;
      }
      if (analogRead(LEFT) > 500)
      {
        lcd.Clear();
        lcd.Display();
        static bool back_loading = true;
        if (back_loading)
        {
          loading();
          lcd.Clear();
          lcd.Display();
          back_loading = false;
        }
        status_computer = 0;
        delay(300);
      }
      menu_snake();
    }
    if (not start_game) snake_xenzia((4 - level_of_difficult) * 10);
  }
  if (status_computer == 2)
  {
    loading_once();
    calculator();
  }
}
