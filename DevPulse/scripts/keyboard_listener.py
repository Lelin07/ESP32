import asyncio
import websockets
from pynput import keyboard

# WebSocket server address (replace with your ESP32's IP and port)
ESP32_WS_URL = "ws://0.0.0.0:81"  # Replace with your ESP32's actual IP address

async def send_keystroke(key):
    try:
        async with websockets.connect(ESP32_WS_URL) as websocket:
            await websocket.send(key)
    except Exception as e:
        print(f"Failed to send keystroke: {e}")

def on_press(key):
    try:
        # Convert the key to a string
        key_str = key.char if hasattr(key, 'char') else str(key)
        print(f"Key pressed: {key_str}")
        # Send the key asynchronously
        asyncio.run(send_keystroke(key_str))
    except Exception as e:
        print(f"Error: {e}")

def main():
    print("Listening for keystrokes...")
    with keyboard.Listener(on_press=on_press) as listener:
        listener.join()

if __name__ == "__main__":
    main()