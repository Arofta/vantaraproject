const {
    EmbedBuilder
} = require('discord.js');

module.exports = (accountName, verifyCode) => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Create Account')
        .setDescription(
            'Akun kamu berhasil didaftarkan kedalam database kami.\n\n' +
            '**Account Name**\n' + 
            `\`\`\`${accountName}\`\`\`\n` + 

            '**Status**\n' + 
            '```Unverified```\n' + 

            '**Verification Code**\n' + 
            `\`\`\`${verifyCode}\`\`\`\n`
        )
        .setColor('#FFD700')
        .setTimestamp();
};