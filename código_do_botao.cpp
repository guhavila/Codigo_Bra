void loop() {
  button = digitalRead(buttonpin);

  if (button && !oldbutton) { // mesma condição que if (button == HIGH && oldbutton == LOW)
    // temos um novo pressionamento do botão
    if (state == 0) { // se o estado estiver desligado, ligue-o
      Serial.println("estou aqui 1");
      state = 1;
      delay(1000);
    } else { // se o estado estiver ligado, desligue-o
      Serial.println("estou aqui 2");
      delay(1000);
      state = 0;
    }
    oldbutton = 1;
  } else if (!button && oldbutton) { // mesma condição que if (button == LOW && oldbutton == HIGH)
    // o botão foi solto
    Serial.println("trocando");
    oldbutton = 0;
  }

  delay(15);
}
