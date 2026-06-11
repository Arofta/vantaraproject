const {
    EmbedBuilder
} = require('discord.js');

module.exports = (accountName, accountStatus, accountCode) => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Account Recovery')
        .setDescription(
            'Akun kamu saat ini sudah dalam status pemulihan.\n\n' +
            '**Account Name**\n' + 
            `\`\`\`${accountName}\`\`\`\n` + 

            '**Status**\n' + 
            `\`\`\`${accountStatus}\`\`\`\n` + 

            `**${accountStatus} Code**\n` + 
            `\`\`\`${accountCode}\`\`\`\n`
        )
        .setColor('#FFD700')
        .setTimestamp();
};