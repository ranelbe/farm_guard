from flask import Flask, Response, request
import requests

# ===================== CONFIGURATION =====================
PORT = 5002
TOKEN = ''
TELEGRAM_INIT_WEBHOOK_URL = 'https://api.telegram.org/bot{}/setWebhook?' \
    'url=https://3c00-82-80-173-170.ngrok-free.app/message'.format(TOKEN)
ALERT_MSG = 'Alert: Snakes detected in your coop. Please take immediate action to ensure the safety of your animals.'
CHAT_ID = '876438964'

# ===================== INITIALIZATION =====================
app = Flask(__name__)


# ===================== ROUTES =============================
# sanity route to check if server is running
@app.route('/sanity')
def sanity():
    return "Server is running"


# get message from telegram route
@app.route('/message', methods=['POST'])
def handle_message():
    data = request.json
    res = requests.get("https://api.telegram.org/bot{}/sendMessage?chat_id={}&text={}"
                       .format(TOKEN, CHAT_ID, data['text']))
    return Response("success")


if __name__ == '__main__':
    requests.get(TELEGRAM_INIT_WEBHOOK_URL)
    app.run(port=PORT)


