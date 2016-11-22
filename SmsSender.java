// Install the Java helper library from twilio.com/docs/java/install
import com.twilio.Twilio;
import com.twilio.rest.api.v2010.account.Message;
import com.twilio.type.PhoneNumber;

import java.net.URISyntaxException;

public class SmsSender {

    // Find your Account Sid and Auth Token at twilio.com/console
    public static final String ACCOUNT_SID = "ACdb2ae7bc6acca31298d5d54ed0875252";
    public static final String AUTH_TOKEN = "1845f02672bc500395daacd26f29a7ff";

    public static void main(String[] args) throws URISyntaxException {
        Twilio.init(ACCOUNT_SID, AUTH_TOKEN);

        Message message = Message
                .creator(new PhoneNumber("+15674954214 "),  // to
                         new PhoneNumber("+9514734643"),  // from
                         "Where's Wallace?")
                .create();
    }
}

