#import <Foundation/Foundation.h>
#import "QCQL_RendererProtocols.h"




//	fired on prepareToBeDeleted, shortly before the agent is released
@protocol QCQLRendererAgentDelegate
- (void) agentKilled:(id)renderer;
@end




/*	instances of this class are created automatically by QCQL_RendererAppDelegate, which is listening 
	for XPC connections on a mach service.  it's basically a throwaway class- an instance is created 
	by the listener, the instance is told to render a frame, and when it's done rendering (or the 
	frame times out) the instance passes its data along and then kills itself
*/




@interface QCQLRendererAgent : NSObject <QCQLAgentService>	{
	BOOL				deleted;
	OSSpinLock			connLock;
	NSXPCConnection		*conn;
	
	OSSpinLock			timerLock;
	NSTimer				*ttlTimer;	//	makes sure that this instance kills itself if it takes "too long" to render a frame
	
	OSSpinLock			delegateLock;
	id<QCQLRendererAgentDelegate>	delegate;
}

//	kills the connection, kills the TTL timer, notifies the delegate that this agent has been killed
- (void) prepareToBeDeleted;

- (void) setConn:(NSXPCConnection *)n;

- (void) setDelegate:(id<QCQLRendererAgentDelegate>)n;
- (id<QCQLRendererAgentDelegate>) delegate;

@end
