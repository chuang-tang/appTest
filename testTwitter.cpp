#include "testTwitter.h"

int main( int argc, char* argv[] )
{

    twitCurl twitterObj;
    std::string tmpStr, tmpStr2;
    std::string replyMsg;
    char tmpBuf[1024];

    /* OAuth flow begins */
    /* Step 0: Set OAuth related params. These are got by registering your app at twitter.com */
    twitterObj.getOAuth().setConsumerKey( std::string( "C65GavtfFCZApq7kYz4w" ) );
    twitterObj.getOAuth().setConsumerSecret( std::string( "JH7KS1B0zKldhkay4mN9yA5DvVNlQYOhAYAYqcwNc14" ) );

    /* Step 1: Check if we alredy have OAuth access token from a previous run */
    std::string myOAuthAccessTokenKey("371718714-whlxhOIrUy6I4L5DyGlujIeutr9ufkO9IBP9crql");
    std::string myOAuthAccessTokenSecret("ul1FWGsnJdMzGZncw9kG91sGwA07nIgtrERfzix3bb0L0");

    /* If we already have these keys, then no need to go through auth again */
    printf( "\nUsing:\nKey: %s\nSecret: %s\n\n", myOAuthAccessTokenKey.c_str(), myOAuthAccessTokenSecret.c_str() );

    twitterObj.getOAuth().setOAuthTokenKey( myOAuthAccessTokenKey );
    twitterObj.getOAuth().setOAuthTokenSecret( myOAuthAccessTokenSecret );

 
    /* Search a string */
    tmpStr="app";
    tmpStr2="1";
    replyMsg = "";
    if( twitterObj.search( tmpStr, tmpStr2 ) )
    {
        twitterObj.getLastWebResponse( replyMsg );
        printf( "\ntwitterClient:: twitCurl::search web response:\n%s\n", replyMsg.c_str() );
    }
    else
    {
        twitterObj.getLastCurlError( replyMsg );
        printf( "\ntwitterClient:: twitCurl::search error:\n%s\n", replyMsg.c_str() );
    }

    return 0;
}
