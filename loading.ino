void loading()
{
  lcd.Asc_String(14, 8, PSTR("Loading..."), 1);
  lcd.Rect(17, 21, 50, 6, 1);
  lcd.Display();
  for (int i = 0; i <= 50; i++)
  {
    lcd.FillRect(17, 21, i, 6, 1);
    lcd.Display();
    delay(10);
  }
}
