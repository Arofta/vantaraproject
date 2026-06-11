const {
    EmbedBuilder
} = require('discord.js');

module.exports = (member) => {

    return new EmbedBuilder()
        .setTitle(`Selamat Datang ${member.user.globalName}`)
        .setDescription(
            `Selamat datang ${member} di **${member.guild.name}**!\n` + 
            `Jangan lupa membaca Aturan dan Ketentuan yang berlaku di server!\n\n` +
            `**Important Channel**\n` +
            `- <#1511693331359465662> Verifikasi Akun Discord.\n` +
            `- <#1511978686172233788> Membuat Akun baru.\n` +
            `- <#1511694413800411308> Pertanyaan yang Sering Diajukan.\n` +
            `- <#1511694176272777277> Aturan Server.\n` +
            `- <#1511711998361211041> Informasi Penting.\n`
        )
        //.setThumbnail(member.user.displayAvatarURL())
        .setThumbnail(member.guild.iconURL())
        .setColor('#FFD700')
        .setTimestamp();
};