//
//  JMCASIHTTPRequestDelegate.h
//  Part of JMCASIHTTPRequest -> http://allseeing-i.com/ASIHTTPRequest
//
//  Created by Ben Copsey on 13/04/2010.
//  Copyright 2010 All-Seeing Interactive. All rights reserved.
//

@class JMCASIHTTPRequest;

@protocol JMCASIHTTPRequestDelegate <NSObject>

@optional

// These are the default delegate methods for request status
// You can use different ones by setting didStartSelector / didFinishSelector / didFailSelector
- (void)requestStarted:(JMCASIHTTPRequest *)request;
- (void)request:(JMCASIHTTPRequest *)request didReceiveResponseHeaders:(NSDictionary *)responseHeaders;
- (void)request:(JMCASIHTTPRequest *)request willRedirectToURL:(NSURL *)newURL;
- (void)requestFinished:(JMCASIHTTPRequest *)request;
- (void)requestFailed:(JMCASIHTTPRequest *)request;
- (void)requestRedirected:(JMCASIHTTPRequest *)request;

// When a delegate implements this method, it is expected to process all incoming data itself
// This means that responseData / responseString / downloadDestinationPath etc are ignored
// You can have the request call a different method by setting didReceiveDataSelector
- (void)request:(JMCASIHTTPRequest *)request didReceiveData:(NSData *)data;

// If a delegate implements one of these, it will be asked to supply credentials when none are available
// The delegate can then either restart the request ([request retryUsingSuppliedCredentials]) once credentials have been set
// or cancel it ([request cancelAuthentication])
- (void)authenticationNeededForRequest:(JMCASIHTTPRequest *)request;
- (void)proxyAuthenticationNeededForRequest:(JMCASIHTTPRequest *)request;

@end
