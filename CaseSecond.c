CaseSecond()
{
	/* case2 start */

	web_reg_save_param_ex(
    "ParamName=PriceFirstTicket", 
    "LB/IC=Total Charge: ",
    "RB/IC= <BR/> (CC: x-)",
    "Ordinal=1",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=FirstClass", 
    "LB/IC=A First class",
    "RB/IC= for",
    "Ordinal=all",
	LAST);

	web_url("welcome.pl", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	lr_output_message( "First ticket price %s", lr_eval_string( "{PriceFirstTicket}" ) );

	lr_output_message( "Number of first class tickets : %s", lr_eval_string( "{FirstClass_count}" ) );
	
	return 0;
}
