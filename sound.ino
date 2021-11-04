int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {4, 8};
void sound()
{
  for (int thisNote = 0; thisNote < 2; thisNote++)
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(7, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(7);
  }
}
