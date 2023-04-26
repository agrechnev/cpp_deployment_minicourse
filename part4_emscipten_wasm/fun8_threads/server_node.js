"use strict";

let http = require('http');
let fs = require('fs');
let path = require('path');

console.log('Creating server http://localhost:8000');

http.createServer((req, res) => {
  let filePath = '.' + req.url;
  if (filePath == './')
      filePath = './index.html';
  let extname = path.extname(filePath);
  let contentType = 'text/html; charset=utf8';
  
  if (extname ==  '.js')
    contentType = 'text/javascript';
  else if (extname ==  '.wasm')
    contentType = 'application/wasm';
  
  console.log('filePath =', filePath, ', extname=', extname, ', contentType=', contentType);
  
  
  fs.readFile(filePath, (err, data) => {
    if (err) {
      res.writeHead(404);
    } else {
      res.writeHead(200, {
        'Content-Type': contentType,
        'Cross-Origin-Opener-Policy': 'same-origin',
        'Cross-Origin-Embedder-Policy': 'require-corp',
      });
      res.write(data);
    }
    return res.end();
  });
}).listen(8000);
