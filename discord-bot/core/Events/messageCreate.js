const accountPanel =
    require('../Components/accountPanel');

const accountButton =
    require('../Components/accountButton');

const welcomeEmbed =
    require('../Components/welcomeEmbed')

module.exports = {
    name: 'messageCreate',

    async execute(message) {

        if (message.author.bot) return;

        if (message.content === '--panel') {

            if (!message.member.roles.cache.has(process.env.ROLE_ADMIN)) {
                return message.reply({
                    content: 'Lau siape mpruy',
                    ephemeral: true
                });
            }

            await message.channel.send({
                embeds: [accountPanel()],
                components: [accountButton()]
            });
        } else if (message.content === '--f.join') {

            const channel =
                message.member.guild.channels.cache.get(process.env.CHANNEL_WELCOME);
    
            if (!channel) return;
    
            await channel.send({
                embeds: [welcomeEmbed(message.member)]
            });
        }
    }
};