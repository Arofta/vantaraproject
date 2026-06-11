const welcomeEmbed =
    require('../Components/welcomeEmbed')

module.exports = {
    name: 'guildMemberAdd',

    async execute(member) {

        const channel =
            member.guild.channels.cache.get(process.env.CHANNEL_WELCOME);

        if (!channel) return;

        await channel.send({
            embeds: [welcomeEmbed(member)]
        });
    }
};