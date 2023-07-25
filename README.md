# Smart Plant Monitoring System using ESP8266

This project implements a Smart Plant Monitoring System using ESP8266. It reads the soil moisture level, temperature, humidity, and pressure using sensors and sends the data to a server or cloud platform for monitoring and analysis.

## Components

- ESP8266 board
- Soil moisture sensor
- BME280 sensor (for temperature, humidity, and pressure)
- Jumper wires
- Breadboard

## Setup

1. Connect the components according to the circuit diagram.
2. Install the necessary libraries in your Arduino IDE: `ESP8266WiFi`, `Wire`, `Adafruit_Sensor`, and `Adafruit_BME280`.
3. Replace the placeholders in the code (`your_SSID`, `your_PASSWORD`, `your_server_endpoint.com`) with your Wi-Fi network credentials and server/cloud endpoint.
4. Upload the code to your ESP8266 board.
5. Power up the circuit and monitor the sensor readings.

## Usage

- The system will read the soil moisture level, temperature, humidity, and pressure periodically.
- The sensor readings will be printed to the serial monitor.
- The data will also be sent to the specified server/cloud endpoint using an HTTP GET request.
- Monitor the data on the server/cloud platform for plant monitoring and analysis.

## Troubleshooting

- If you encounter any issues, double-check the wiring connections and ensure that the libraries are properly installed.
- Make sure the Wi-Fi network credentials and server/cloud endpoint are correct.
- Refer to the comments in the code for more information and troubleshooting tips.

## Credits

- This project uses the `Adafruit_BME280` library for the BME280 sensor.
- Special thanks to the ESP8266 community for their contributions and support.

## License

This project is licensed under the [MIT License](LICENSE).
