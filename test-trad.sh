




Slide 2 / Vulnerable Code Example
# Retrieves user input without validation
user_name = "User input"
# The SQL query is directly constructed with the user input
query = "SELECT * FROM users WHERE name = '" + user_name + "';"
# Executes the potentially dangerous query without protection
execute(query)





Slide 2 / Corrected Code Example

# Retrieves user input
user_name = "User input"
# Uses a prepared query with a parameter
query = "SELECT * FROM users WHERE name = ?"
# The user parameter is handled separately, preventing any malicious injection
execute(query, [user_name])


Slide 2 / Malicious Code Example

User input: ' OR '1'='1'
SQL Query:
    SELECT * FROM users WHERE name = '' OR '1'='1'; '





Slide 3 / Vulnerable Code Example

function verify_user(name, password):
    # Checks password in plain text, vulnerable to attacks
    if name is in database and password matches:
        return "Login successful"
    else:
        return "Failed"


Slide 3 / Corrected Code Example

function verify_user(name, password):
    # Retrieves the hashed password from the database
    stored_hash = get_hash(name)
    # Secure comparison with the hash algorithm
    if check_hash(password, stored_hash):
        return "Login successful"
    else:
        return "Failed"



Slide 3 / Malicious Code Example
# weak password
password = "12345"
check(password)




Slide 4 / Vulnerable Code Example

function send_data(card_number):
    # Data is sent in plain text over an unsecured connection
    send("http://site.com/payment", card_number)


Slide 4 / Corrected Code Example

function send_data(card_number):
    # Data is encrypted and transmitted via HTTPS for enhanced security
    send("https://site.com/payment", encrypt(card_number))


Slide 4 / Malicious Code Example
# Sends sensitive data in clear text
transmit_data(card_number = "1234-5678-9012-3456",
''                     "http://site.com/payment")
