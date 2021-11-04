void loading_once()
{
  static bool _loading = true;
    if (_loading)
    {
      loading();
      lcd.Clear();
      lcd.Display();
      _loading = false;
    }
}
