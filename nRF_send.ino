void nRF_send(int angleNum, int timerInterval) 
{
  text[0] = RF_LETTER;

  switch(angleNum) {
    case 1:
       dtostrf(pitch,ANGLE_BUF_SIZE-1,ANGLE_DECIMAL_SIZE,buf_pitch);
       for(int i=0; i<ANGLE_BUF_SIZE; i++) {
          text[i+1] = buf_pitch[i];
       }
    break;
    
    case 2:
       dtostrf(pitch,ANGLE_BUF_SIZE-1,ANGLE_DECIMAL_SIZE,buf_pitch);
       for(int i=0; i<ANGLE_BUF_SIZE; i++) {
          text[i+1] = buf_pitch[i];
       }
       dtostrf(yaw,ANGLE_BUF_SIZE-1,ANGLE_DECIMAL_SIZE,buf_yaw);
       for(int i=0; i<ANGLE_BUF_SIZE; i++) {
          text[i+ANGLE_BUF_SIZE+1] = buf_yaw[i];
       }           
    break;
    
    case 3:
       dtostrf(pitch,ANGLE_BUF_SIZE-1,ANGLE_DECIMAL_SIZE,buf_pitch);
       for(int i=0; i<ANGLE_BUF_SIZE; i++) {
          text[i+1] = buf_pitch[i];
       }
       dtostrf(yaw,ANGLE_BUF_SIZE-1,ANGLE_DECIMAL_SIZE,buf_yaw);
       for(int i=0; i<ANGLE_BUF_SIZE; i++) {
          text[i+ANGLE_BUF_SIZE+1] = buf_yaw[i];
       }       
       dtostrf(pitch,ANGLE_BUF_SIZE-1,ANGLE_DECIMAL_SIZE,buf_roll);
       for(int i=0; i<ANGLE_BUF_SIZE; i++) {
          text[i+2*ANGLE_BUF_SIZE+1] = buf_roll[i];
       }        
    break;

    default:
    break;
  }

  if( (millis()- timer_rf)>timerInterval )
  {
    timer_rf = millis();
    radio.write(&text,sizeof(text));
//    Serial.println(text[ANGLE_BUF_SIZE+2]);
    Serial.println(pitch);
    Serial.println(yaw);
    Serial.println(roll);
  }  
}

