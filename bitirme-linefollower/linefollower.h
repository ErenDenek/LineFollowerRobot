void calibration(int duration)
{
  while (millis() < duration)
  {
    for (int i = 0; i < 6; i++)
    {
      if (analogRead(analogPin[i]) > maxVal[i]) maxVal[i] = analogRead(analogPin[i]);
      else if (analogRead(analogPin[i]) < minVal[i]) minVal[i] = analogRead(analogPin[i]);
    }
  }
}

void readQtr()
{
  for (int i = 0; i < 6; i++)
  {
    sens[i] = analogRead(analogPin[i]);
    sens[i] = map(sens[i], minVal[i], maxVal[i] , 30, 1000);
  }
}
void averageCal()
{
  readQtr();
  for (int i = 0; i < 6; i++) {
    numerator += sens[i] * i * 1000;
    denominator += sens[i];
  }
  average = numerator / denominator;
}


int pid(int target, int value) {
  float pidTerm;
  int error;
  static int last_error;
  static int sum_error;
  error = targer - value;
  pidTerm = (error) * kp + (error - last_error) * kd;
  last_error = error;
  return (int(pidTerm));
}

void motorControl()
{
  averageCal();
  int pidVal = pid(2500, average);

  rM = maxSpeed - pidVal;
  lM = maxSpeed + pidVal;

  if(rM > 255) rM = 255;
  else if(rM < 0) rM =0;
  if(lM > 255) lM = 255;
  else if(lM < 0) lM =0;

  analogWrite(in1, lM);
  analogWrite(in2, 0);
  analogWrite(in3, rM);
  analogWrite(in4, 0);
  
}
