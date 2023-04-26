Fun 8: Multithread example with Web Workers
============

It will NOT run with the default server. You have to set a couple of HTTP response header properties,
in order to enable Cross-Origin Isolation Mode and thus SharedArrayBuffer.

I wrote a NodeJS script which runs the server:  
`node server_node.js`

Also, you must open this page as `localhost:8000`, things like `0.0.0.0:8000` will NOT work!
