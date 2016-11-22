from twilio.rest import TwilioRestClient
 


ACCOUNT_SID = "ACdb2ae7bc6acca31298d5d54ed0875252"
AUTH_TOKEN = "1845f02672bc500395daacd26f29a7ff"
 
client = TwilioRestClient(ACCOUNT_SID, AUTH_TOKEN)
nopill=True



client.messages.create(
	to="+19514734643",
	from_="+15674954214 ",
	body="Take your meds.",
   	 
	)

