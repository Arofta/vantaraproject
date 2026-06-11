const {
    EmbedBuilder
} = require('discord.js');

module.exports = () => {

    return new EmbedBuilder()
        .setTitle('Account Panel')
        .setDescription(
            ':heavy_plus_sign:__**Create Account**__\n' + 
            '> Tombol ini digunakan untuk membuat akun baru.\n\n\n' + 

            ':mag:__**Check Account**__\n' + 
            '> Tombol ini digunakan untuk memeriksa informasi akun yang tertaut pada discord account kamu.\n\n\n' + 

            ':closed_lock_with_key:__**Account Recovery**__\n' + 
            '> Tombol ini digunakan untuk memulihkan akun (reset/ganti password).\n\n\n' + 

            ':recycle:__**Reffund Role**__\n' + 
            '> Tombol ini digunakan untuk mengambil role Warga bagi pemain yang kehilangan role discord'
        )
        .setColor('#FFD700')
        .setTimestamp();
};