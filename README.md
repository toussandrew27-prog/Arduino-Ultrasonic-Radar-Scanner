# 🟢 Arduino Ultrasonic Radar Scanner

## 📝 Description
Ce projet est un système de radar fonctionnel inspiré de l'aéronautique. L'Arduino pilote un servomoteur balayant un angle de 180°, prend des mesures de distance via un capteur à ultrasons, et envoie ces données en temps réel via communication Série à un ordinateur. Une interface graphique développée sous Processing dessine la carte radar en direct. 

L'appareil intègre également un système de retour visuel et sonore (LED RGB et Buzzer) dont l'intensité augmente à l'approche de l'obstacle, simulant un radar de recul automobile.

## 🛠️ Matériel Utilisé (Hardware)
* Arduino Uno
* Capteur Ultrason (HC-SR04)
* Servomoteur (SG90)
* Écran LCD 16x2
* LED RGB (Cathode commune)
* Buzzer Actif

## 💻 Technologies & Langages (Software)
* **C / C++** (Architecture embarquée, logique asynchrone avec `millis()`)
* **Java / Processing** (Interface graphique, lecture du port Série)

## 📸 Démonstration
<video src="[[COLLE_TON_LIEN_GITHUB_ICI](https://github.com/user-attachments/assets/4d7f1274-cceb-420a-8263-315c752ad3a0)]" width="100%" height="auto" autoplay loop muted controls></video>
