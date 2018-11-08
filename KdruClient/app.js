// Module import by npm
const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const _ = require('lodash');
// const pug = require('pug');

// Module instance
const app = express();
const server = require('http').createServer(app);

// Router instance
const router = express.Router();


router.use(bodyParser.json());

// path vers les ressources;
router.use('/css', express.static(`${__dirname}/views/css`));
router.use('/js', express.static(`${__dirname}/views/js`));
router.use('/data', express.static(`${__dirname}/views/data`));
router.use('/img', express.static(`${__dirname}/views/img`));
router.use('/template', express.static(`${__dirname}/views/template`));

// path de redirection
// Path /
router.get('/', (req, res) => {
    fs.readFile('./views/app.html', 'utf-8', (error, content) => {
      res.writeHead(200, {
        'Content-Type': 'text/html',
      });
      res.end(content);
    });
  });


// mount the router on the app
app.use('/', router);

// define listening port of server
server.listen(3000);
console.log('App Launched on post 3000 ');

