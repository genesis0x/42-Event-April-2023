import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

# Email details
from_email = 'your_email@example.com'
to_email = 'recipient@example.com'
subject = 'Test Email with Attachment'
body = 'This is a test email with an attachment.'

# Attachment file details
attachment_file = 'path/to/attachment/file.pdf'

# Set up the email message
msg = MIMEMultipart()
msg['From'] = from_email
msg['To'] = to_email
msg['Subject'] = subject

# Add the message body
msg.attach(MIMEText(body, 'plain'))

# Add the attachment file
with open(attachment_file, 'rb') as attachment:
    part = MIMEBase('application', 'octet-stream')
    part.set_payload(attachment.read())
    encoders.encode_base64(part)
    part.add_header('Content-Disposition', f"attachment; filename= {attachment_file}")
    msg.attach(part)

# Send the email using SMTP
smtp_server = 'smtp.example.com'
smtp_port = 587
smtp_username = 'your_email_username'
smtp_password = 'your_email_password'

with smtplib.SMTP(smtp_server, smtp_port) as server:
    server.starttls()
    server.login(smtp_username, smtp_password)
    server.sendmail(from_email, to_email, msg.as_string())
