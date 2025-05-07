# import streamlit as st
# import nltk
# from nltk.chat.util import Chat, reflections
# # import re

# # Download required NLTK data
# nltk.download('punkt')

# # Define chatbot pairs
# pairs = [
#     [
#         r"(?i)hi|hello|hey",
#         ["Hello! How can I assist you today?", "Hi there! What can I help you with?"]
#     ],
#     [
#         r"(?i).*(hours|timing|open|close).*",
#         ["Our store is open from 9 AM to 9 PM, Monday to Saturday."]
#     ],
#     [
#         r"(?i).*(location|address|where).*",
#         ["We are located at 123 Main Street, Springfield."]
#     ],
#     [
#         r"(?i).*(services|products|offerings).*",
#         ["We offer a range of electronics, mobile accessories, and repair services."]
#     ],
#     [
#         r"(?i).*(contact|phone|email).*",
#         ["You can contact us at support@example.com or call 123-456-7890."]
#     ],
#     [
#         r"(?i)bye|goodbye|exit",
#         ["Goodbye! Have a great day!", "Thanks for visiting. Bye!"]
#     ],
#     [
#         r"(.*)",
#         ["I'm sorry, I didn't understand that. Can you please rephrase?"]
#     ]
# ]

# # Create chatbot instance
# chatbot = Chat(pairs, reflections)

# # Streamlit UI
# st.set_page_config(page_title="Customer Chatbot", layout="centered")
# st.title("🛍️ Customer Service Chatbot")

# # Store chat history in session state
# if "chat_history" not in st.session_state:
#     st.session_state.chat_history = []

# # Input from user
# user_input = st.text_input("You:", key="user_input_input")

# # Only process input if it's non-empty
# if user_input.strip():
#     response = chatbot.respond(user_input)
#     st.session_state.chat_history.append(("You", user_input))
#     st.session_state.chat_history.append(("Bot", response))

# # Display conversation
# for sender, message in st.session_state.chat_history:
#     st.markdown(f"**{sender}:** {message}")



import streamlit as st
import nltk
from nltk.chat.util import  Chat, reflections

nltk.download('punkt')

pairs = [
    [
        r"(?i)hii|hello|hey",
        ["Hello , how can I help you"]
    ],
    [
        r"(?i).*(date|time|hours|open|close).*",
        ["Our store is open from 9 AM to 9 PM, Monday to Saturday."]
    ]
]


chatbot = Chat(pairs, reflections)
chatbot.converse()

st.set_page_config(page_title="Customer Service", layout="centered")
st.title("Cusomer Chatbot")

# if 'chat_history' not in st.session_state:
#     st.session_state.chat_history = []

# user_input = st.text_input("You", key="user_input_input")


# if user_input.strip():
#     response = chatbot.respond(user_input)
#     st.session_state.chat_history.append(("You", user_input))
#     st.session_state.chat_history.append(("Bot", response))


# for sender, message in st.session_state.chat_history:
#     st.markdown(f"**{sender}:** {message}")    

