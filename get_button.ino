int u = analogRead(UP);
int d = analogRead(DOWN);
int r = analogRead(RIGHT);
int l = analogRead(LEFT);
int get_button()
{
  if (u > 500)
  {
    return 1;
  }
  if (d > 500)
  {
    return -1;
  }
  if (r > 500)
  {
    return -2;
  }
  if (l > 500)
  {
    return 2;
  }
}
