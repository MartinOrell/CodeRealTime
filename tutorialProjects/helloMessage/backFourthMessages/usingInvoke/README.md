This contains an example using evoke.\
Requirements for using evoke:\
1. The connection must be made before calling evoke
2. Both capsules involved must be on the same thread (RTController)

A good idea is to use a notify port and not send an invoke before the rtBound event is reached.