
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

// path de redirection
// Path /
router.get('/', (req, res) => {
    fs.readFile('./views/home.html', 'utf-8', (error, content) => {
      res.writeHead(200, {
        'Content-Type': 'text/html',
      });
      res.end(content);
    });
  });
