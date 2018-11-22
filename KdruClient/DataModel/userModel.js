// Require Mongoose
const mongoose = require('mongoose'); // mongoDB client
const bcrypt = require('bcrypt'); // crypter

const SALT_WORK_FACTOR = 10; // cryptation degree
// const MAX_LOGIN_ATTEMPTS = 5; // number of try to connect
// const LOCK_TIME = 2 * 60 * 60 * 1000; // Locking Account time

// Define a schema
const Schema = mongoose.Schema;

const userSchema = new Schema({
  name: { type: String, required: true },
  firstname: String,
  username: {
    type: String,
    required: true,
    unique: true,
  },
  mail: {
    type: String,
    required: true,
    unique: true,
  },
  password: {
    type: String,
    required: true,
  },
  phoneNumber: String,
  created_at: Date,
  updated_at: Date,
  loginAttempts: { type: Number, required: true, default: 0 },
  lockUntil: { type: Number },
});

// A chaque enregistrement en base
userSchema.pre('save', function(next) {
  console.log("Saving")

  console.log(this)
  let user = this
  // change the updated_at field to current date
  user.updated_at = new Date();

  // if created_at doesn't exist, add to that field
  if (!user.created_at) { user.currentDate = user.created_at; }

  console.log("Password : " + user.password)
  console.log("Name : " + this.name)
  console.log("Mail : " + this.mail)
  // if (!user.isModified('password')) return next();

  // generate a salt
  bcrypt.genSalt(SALT_WORK_FACTOR, (err, salt) => {
    if (err) return err;
    console.log(user)
    // hash the password using our new salt
    bcrypt.hash(user.password, salt, (errCrypt, hash) => {
      if (errCrypt) return errCrypt;
      console.log("Hash = "+ hash)
      // override the cleartext password with the hashed one
      user.password = hash;
      next();
    });
  });
});

// ajout de la methode permettant de comparer les mots de passe.
userSchema.methods.comparePassword = async function (candidatePassword) {
  console.log(`Candidat = ${candidatePassword}`);
  console.log(`Password to compare = ${this.password}`);
  bcrypt.compare(candidatePassword, this.password);
};

userSchema.statics.getAuthenticated = async function (username, password) {
  console.log("Authenticating")
  const user = await this.findOne({ username });
  if (!user) return null;

  console.log("user found")
  console.log(user)

  const isSame = await bcrypt.compare(password, user.password);
  if (!isSame) return null;

  console.log("password confirmed")
  return user;
};

userSchema.statics.getAllUsers = async function () {
  const userlist = await this.find();
  if (!userlist) return null;
  console.log(userlist);
  return userlist;
};

// Compile model from schema
// export default mongoose.model('User', userSchema);
module.exports = mongoose.model('User', userSchema);
